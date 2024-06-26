#mqtt_realapp.py
# 온습도센서데이터 통신, RGB LED Setting
# MQTT -> json transfer

import paho.mqtt.client as mqtt
import RPi.GPIO as GPIO
import adafruit_dht
import board
import time
import datetime as dt
import json
import io

red_pin = 4
green_pin = 6
blue_pin = 5
dht_pin = 18

dev_id = 'pknu55'
loop_num = 0

## 초기화 시작
def onConnect(client,userdata,flags,reason_code,properties):
    print(f'연결 성공 : {reason_code}')
    client.subscribe('pknu/rcv/')
    # RGB LED 끄기
    GPIO.output(red_pin,GPIO.HIGH)
    GPIO.output(green_pin,GPIO.HIGH)
    GPIO.output(blue_pin,GPIO.HIGH)

def onMessage(client,userdata,msg):
    #print(f'{msg.topic} + {msg.payload}')
    # byte code -> string
    # json ' -> "
    value = json.loads(msg.payload.decode('utf-8').replace("'",'"'))
    res = value['control']
    if res == 'warning':
        GPIO.output(blue_pin,GPIO.HIGH)
        GPIO.output(green_pin,GPIO.HIGH)
        GPIO.output(red_pin,GPIO.LOW)
    elif res == 'normal':
        GPIO.output(blue_pin,GPIO.HIGH)
        GPIO.output(green_pin,GPIO.LOW)
        GPIO.output(red_pin,GPIO.HIGH)
    elif res == 'off':
        GPIO.output(blue_pin,GPIO.HIGH)
        GPIO.output(green_pin,GPIO.HIGH)
        GPIO.output(red_pin,GPIO.HIGH)

GPIO.cleanup()
GPIO.setmode(GPIO.BCM)
GPIO.setup(red_pin, GPIO.OUT)
GPIO.setup(green_pin, GPIO.OUT) # LED 켜는 것
GPIO.setup(blue_pin, GPIO.OUT)
GPIO.setup(dht_pin,GPIO.IN) # 온습도값을 RPi에서 받는 것
dhtDevice = adafruit_dht.DHT11(board.D18) 

## 초기화 끝

## 실행시작
mqttc = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2) #2023.9 이후 버전업
mqttc.on_connect = onConnect # 접속시 이벤트 
mqttc.on_message = onMessage # messaging

# 192.168.5.2 window ip
mqttc.connect('192.168.5.2',1883,60)

mqttc.loop_start()
while True:
    time.sleep(2)

    try:
        # 온습도 값 받아서 MQTT로 전송
        temp = dhtDevice.temperature
        humid = dhtDevice.humidity
        print(f'{loop_num} - Temp:{temp}/humid:{humid}')

        origin_data = {'DEV_ID' : dev_id,
                       'CURR_DT' : dt.datetime.now().strftime('%Y-%m-%d %H:%M:%S'),
                       'TYPE' : 'TEMPHUMID',
                       'VALUE' : f'{temp}|{humid}'} # dictionary data
        pub_data = json.dumps(origin_data, ensure_ascii=False)

        mqttc.publish('pknu/data/',pub_data)
        loop_num += 1
    except RuntimeError as ex:
        print(ex.args[0])
    except KeyboardInterrupt:
        break

mqttc.loop_stop()
dhtDevice.exit()
##실행 끝
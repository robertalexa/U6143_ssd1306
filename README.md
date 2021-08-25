# U6143_ssd1306
This fork contains alternative display modes. 

C - the original files with a fix to the IP address to use eth0.

C_HostName_IP - updated to display the host name on top and added a 4th display in the loop containing the IP address. 

C_StaticHostName_IP - updated to only display the hostname and IP address.


## Preparation
```bash
sudo raspi-config
```
Choose Interface Options 
Enable i2c

##  Clone U6143_ssd1306 library 
```bash
git clone https://github.com/robertalexa/U6143_ssd1306.git
```
## Rasbian Lite
- If you are running Lite then you will need to manually install wiringpi or you will get an error while compiling
- Ignore this for other version of Raspbian - wiringpi is installed by default
```bash
sudo apt install wiringpi
```

## Compile 
```bash
cd U6143_ssd1306/C

or

cd U6143_ssd1306/C_HostName_IP

```
```bash
sudo make clean && sudo make 
```
## Run 
```
sudo ./display
```

## Add automatic start script
- Open the rc.local file 
```bash
sudo nano /etc/rc.local
```
- Add command to the rc.local file
```bash
cd /home/pi/U6143_ssd1306/C
or
cd /home/pi/U6143_ssd1306/C_HostName_IP
sudo make clean 
sudo make 
sudo ./display &
```
- reboot your system

## Add automatic systemd start to systemd
- replace `C_HostName_IP` folder with whatever version you are using
```bash
sudo systemctl link /home/pi/U6143_ssd1306/C_HostName_IP/ssd1306.service
sudo systemctl enable ssd1306.service
sudo systemctl start ssd1306.service
```

## For older 0.91 inch lcd without mcu 
- For the older version lcd without mcu controller, you can use python demo
- Install the dependent library files
```bash
sudo pip3 install adafruit-circuitpython-ssd1306
sudo apt-get install python3-pip
sudo apt-get install python3-pil
```
- Test demo 
```bash 
cd /home/pi/U6143_ssd1306/python 
sudo python3 ssd1306_stats.py
```











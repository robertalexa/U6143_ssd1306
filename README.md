# U6143_ssd1306
This fork contains alternative display modes. 

C - the original files with a fix to the IP address to use eth0.

C_HostName_IP - updated to display the host name on top and added a 4th display in the loop containing the IP address. 

C_StaticHostName_IP - updated to only display the hostname and IP address.

Replace `C_HostName_IP` in the commands if you plan on using a different display mode.

## Preparation
```bash
sudo raspi-config
```
Go to `Interface Options` and `Enable i2c`

##  Clone U6143_ssd1306 library 
```bash
cd ~/Scripts
git clone https://github.com/robertalexa/U6143_ssd1306.git
```
## Rasbian Lite
- If you are running Lite then you will need to manually install wiringpi or you will get an error while compiling
- Ignore this for other version of Raspbian - wiringpi is installed by default
- If you are running the beta x64 Raspian please read the instruction below about Incompatible WiringPi
```bash
sudo apt install wiringpi
```

## Compile 
```bash
cd ~/Scripts/U6143_ssd1306/C_HostName_IP

```
```bash
sudo make clean && sudo make 
```
## Run 
```
sudo ./display
```

## Incompatible WiringPI
If you get errors when you try to run `sudo make` then you will need to use a different version of WiringPi. The original project is not supported anymore.
```bash
sudo apt remove wiringpi
cd ~/Scripts
git clone https://github.com/WiringPi/WiringPi
cd WiringPi
./build

```
Run the Compile and Run instructions again (above). It should all work now.

PS: I have no affiliation with the author of the WiringPi fork used in these instructions. I also take no responsibility for the code in that repo, should you have any concerns over what it does feel free to look at the repo before using it.

## Recommended - Add automatic systemd service
- replace `C_HostName_IP` folder with whatever version you are using
```bash
sudo systemctl link /home/pi/Scripts/U6143_ssd1306/C_HostName_IP/ssd1306.service
sudo systemctl enable ssd1306.service
sudo systemctl start ssd1306.service
```
This relies on you previously compiling. It will not recompile on its own.

## Alternative - Add automatic script
- Open the rc.local file 
```bash
sudo nano /etc/rc.local
```
- Add command to the rc.local file
```bash
cd /home/pi/Scripts/U6143_ssd1306/C_HostName_IP
sudo make clean 
sudo make 
sudo ./display &
```
- reboot your system

This will recompile every time you boot. A bit wasteful.

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
cd /home/pi/Scripts/U6143_ssd1306/python 
sudo python3 ssd1306_stats.py
```











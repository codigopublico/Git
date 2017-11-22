a=` cat /sys/devices/virtual/thermal/thermal_zone0/temp`
echo $a;
if [ $a < 30 ]
then
gksudo pm-suspend
fi


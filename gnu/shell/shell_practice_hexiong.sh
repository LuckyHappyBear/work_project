#!/bin/sh
echo *********instruction 1:decompression shell_practice.tar.bz2*********
tar -xvf shell_practice.tar.bz2 -C ~/

echo **************instruction 2:enter shell_practice folder*************
cd ~/shell_practice/

echo *****instruction 3:look up the folders and files in this folder*****
ls -la

echo **********instruction 4:look up the folder in recursion way*********
ls -aR

echo *******instruction 5:count the files and folders total number*******
count1=0
count2=0
sum=0
count1=`find ./ -type f | wc -l`
count2=`find ./ -type d | wc -l`
let sum=$count1+$count2-1
echo The total number of files and folders is $sum

echo ************instruction 6:create a folder with my name**************
mkdir hexiong
echo create successful

echo **************instruction 7:copy file_1 to new folder***************
cp file_1 hexiong
echo copy successful

echo ***************instruction 8:let file_1 executable******************
chmod 777 hexiong/file_1
echo opearte successfully

echo *******instruction 9:write all process info in process file.********
cd hexiong
ps -A > process
echo operate successfully

echo ***instruction 10:write lines contain word Intel in file cpuinfo****
cat /proc/cpuinfo > tmpfile
grep 'Intel' tmpfile > cpuinfo
rm -f tmpfile
echo operate successfully

echo *******instruction 11:write the info of memory in file meminfo******
cat /proc/meminfo > meminfo
echo operate successfully

echo ****************instruction 12: excute infi in background***********
cd ..
./exec/infi &
echo operate successfully

echo ************instruction 13:get pid of the process and kill it*******
pidof infi
killall infi
echo operate successfully

echo ***********instruction 14:create a symbolic link point to infi******
cd dir_3
ln -s ../exec/infi
cd ..
echo operate successfully

echo ****instruction 15:search in shell_practice for all mobile_team*****
find ./ -type d | grep -w mobile_team
echo operate successfully

echo *********instruction 16:create a folder named delete_test***********
mkdir delete_test
echo operate successfully

echo ***instruction 17:copy all files and directories into delete_test***
for file in *
do
    if [ -f $file ]
    then
        cp $file delete_test
    fi
    if [ -d $file -a "$file" != "delete_test" ]
    then
        cp -r $file delete_test
    fi
done
echo operate successfully

echo *************instruction 18:delete delete_test directory************
rm -r delete_test
echo opearte successfully

echo ************instruction 19:check the current system time************
echo the time is `date`
echo the hour is `date +%H`
echo opearte successfully

echo *****************instruction 20:get the total size******************
du -c /bin
echo opearte successfully

echo *************isntruction 21:get the ip and mac of eth0**************
NIC=eth0
MAC=`LANG=C ifconfig $NIC | awk '/HWaddr/{ print $5  }' `
IP=`LANG=C ifconfig $NIC | awk '/inet addr:/{ print $2  }' | awk -F: '{print $2 }'`
echo your ip and mac information is as below
echo ip is $IP
echo MAC is $MAC
echo opearte successfully

echo ************instruction 22:shut down the network adapter************
sudo ifconfig eth0 down

echo ********************instruction 23:modify the mac*******************
sudo ifconfig eth0 hw ether 00:EB:AA:BB:CC:DD
echo opearte successfully

echo *********************instruction 24:modify the ip*******************
sudo ifconfig eth0 192.168.1.100 netmask 255.255.255.0
echo opearte successfully

echo *************instruction 25:restart the network adapter*************
sudo ifconfig eth0 up
echo opearte successfully

echo ****************instruction 26:reset the mac and ip*****************
sudo ifconfig eth0 down

sudo ifconfig eth0 hw ether 00:0C:29:1A:D2:E2
sudo ifconfig eth0 192.168.192.128 netmask 255.255.255.0

sudo ifconfig eth0 up
echo operate successfully

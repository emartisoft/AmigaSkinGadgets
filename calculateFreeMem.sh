#!/bin/bash
#calculate free memory for RAM
free --kilo | grep "Mem:" | awk -F " " '{print $4'} > /root/memory.txt


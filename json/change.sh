#!/bin/bash
###
 # @Author       : lqm283
 # @Date         : 2023-01-11 08:39:01
 # @LastEditTime : 2023-01-11 08:39:02
 # @LastEditors  : lqm283
 # --------------------------------------------------------------------------------<
 # @Description  : Please edit a descrition about this file at here.
 # --------------------------------------------------------------------------------<
 # @FilePath     : /jsonc/json/uint16/non_arr/mult/bool/change.sh
###


for var in `ls *_uint8_*.json`;
do
    mv "$var" `echo "$var" | awk -F '_uint8_' '{print $1 "_uint16_" $2}'`;
done

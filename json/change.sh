#!/bin/bash
###
 # @Author       : lqm283
 # @Date         : 2023-01-09 08:31:53
 # @LastEditTime : 2023-01-10 17:10:55
 # @LastEditors  : lqm283
 # --------------------------------------------------------------------------------<
 # @Description  : Please edit a descrition about this file at here.
 # --------------------------------------------------------------------------------<
 # @FilePath     : /jsonc/json/uint8/non_arr/mult/bool/change.sh
###

for var in `ls *_char_*.json`;
do
    mv "$var" `echo "$var" | awk -F '_char_' '{print $1 "_uint8_" $2}'`;
done

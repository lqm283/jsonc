#!/bin/bash
###
 # @Author       : lqm283
 # @Date         : 2023-01-09 08:31:53
 # @LastEditTime : 2023-01-09 13:41:35
 # @LastEditors  : lqm283
 # --------------------------------------------------------------------------------<
 # @Description  : Please edit a descrition about this file at here.
 # --------------------------------------------------------------------------------<
 # @FilePath     : /jsonc/json/char/ptr_non/mult/bool/change.sh
###

for var in `ls *_non_non_*.json`;
do
    mv "$var" `echo "$var" | awk -F '_non_non_' '{print $1 "_ptr_non_" $2}'`;
done

#!/bin/bash
###
 # @Author       : lqm283
 # @Date         : 2023-01-09 08:31:53
 # @LastEditTime : 2023-01-09 16:12:15
 # @LastEditors  : lqm283
 # --------------------------------------------------------------------------------<
 # @Description  : Please edit a descrition about this file at here.
 # --------------------------------------------------------------------------------<
 # @FilePath     : /jsonc/json/char/non_arr/mult/bool/change.sh
###

for var in `ls *_ptr_non_*.json`;
do
    mv "$var" `echo "$var" | awk -F '_ptr_non_' '{print $1 "_non_arr_" $2}'`;
done

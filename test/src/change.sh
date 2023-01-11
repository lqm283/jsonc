#!/bin/bash
###
 # @Author       : lqm283
 # @Date         : 2023-01-11 08:15:20
 # @LastEditTime : 2023-01-11 08:15:21
 # @LastEditors  : lqm283
 # --------------------------------------------------------------------------------<
 # @Description  : Please edit a descrition about this file at here.
 # --------------------------------------------------------------------------------<
 # @FilePath     : /jsonc/test/src/change.sh
###
###
 # @Author       : lqm283
 # @Date         : 2023-01-09 08:31:53
 # @LastEditTime : 2023-01-11 08:14:50
 # @LastEditors  : lqm283
 # --------------------------------------------------------------------------------<
 # @Description  : Please edit a descrition about this file at here.
 # --------------------------------------------------------------------------------<
 # @FilePath     : /jsonc/test/src/uint16/change.sh
###

for var in `ls *_uint8*.c`;
do
    mv "$var" `echo "$var" | awk -F '_uint8' '{print $1 "_uint16" $2}'`;
done

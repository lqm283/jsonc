#!/bin/bash
###
 # @Author       : lqm283
 # @Date         : 2023-01-11 08:39:01
 # @LastEditTime : 2023-01-11 10:15:44
 # @LastEditors  : lqm283
 # --------------------------------------------------------------------------------<
 # @Description  : Please edit a descrition about this file at here.
 # --------------------------------------------------------------------------------<
 # @FilePath     : /jsonc/json/int32/change.sh
###


cd int32

firstdir=`ls .`

for fname in ${firstdir}
do
    cd ${fname}
    secenddir=`ls .`
    for sname in ${secenddir}
    do
        cd ${sname}
        thirddir=`ls .`
        for tname in ${thirddir}
        do
            cd ${tname}
            rename 's/_int16_/_int32_/' *.json;
            cd ../
        done
        cd ../
    done
    cd ../
done

cd ..
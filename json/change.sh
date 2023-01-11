#!/bin/bash
###
 # @Author       : lqm283
 # @Date         : 2023-01-11 08:39:01
 # @LastEditTime : 2023-01-11 09:33:50
 # @LastEditors  : lqm283
 # --------------------------------------------------------------------------------<
 # @Description  : Please edit a descrition about this file at here.
 # --------------------------------------------------------------------------------<
 # @FilePath     : /jsonc/json/change.sh
###


cd int16

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
            rename 's/_uint16_/_int16_/' *.json;
            cd ../
        done
        cd ../
    done
    cd ../
done

cd ..
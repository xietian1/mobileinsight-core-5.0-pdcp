#!/usr/bin/python
# Filename: offline-analysis-example.py
import os
import sys
import glob

"""
Offline analysis by replaying logs
"""

# Import MobileInsight modules
from mobile_insight.monitor import OfflineReplayer
from mobile_insight.analyzer import MsgLogger, LteRrcAnalyzer, WcdmaRrcAnalyzer, LteNasAnalyzer, UmtsNasAnalyzer, LtePhyAnalyzer, LteMacAnalyzer, LtePdcpAnalyzer

#put all *.mi2log files to a folder with name "foldername"
def GetFileName(foldername):
    dirpath = os.getcwd()
    if foldername:  
        os.chdir(dirpath + "/" + foldername)
    
    filenames = []
    for file in glob.glob("*.mi2log"):
        filenames.append(file)
    return filenames


def MergeTxtFile(index):
    filenames = []
    for i in range(index):
        filenames.append(str(i) + ".txt")

    with open('combine.txt', 'w') as outfile:
        for fname in filenames:
            with open(fname) as infile:
                outfile.write(infile.read())
    

'''
Usage:

1. put all .mi2log (within one call) to the folder with this file (Make sure no other .mi2log files. It only brute-force search the files end with mi2log)
2. run python3 offline-analysis-example.py 
3. txt results are saved to combine.txt

'''



if __name__ == "__main__":


    filenames = GetFileName("")
    filenames.sort()
    
    
    src = OfflineReplayer()
    logger = MsgLogger()

    
    for i, _file in enumerate(filenames):
        # Initialize a 3G/4G monitor
        #src = OfflineReplayer()
        
        #src.set_input_path("./mi-files/" + _file)
        src.set_input_path("./" + _file)

        #logger = MsgLogger()
        logger.set_decode_format(MsgLogger.XML)
        logger.set_dump_type(MsgLogger.FILE_ONLY)
        logger.save_decoded_msg_as("./" + str(i) + ".txt")
        logger.set_source(src)

        # Analyzers
        #lte_rrc_analyzer = LteRrcAnalyzer()
        #lte_rrc_analyzer.set_source(src)  # bind with the monitor

        lte_pdcp_analyzer = LtePdcpAnalyzer()
        lte_pdcp_analyzer.set_source(src)


        # Start the monitoring
        src.run()
        
    MergeTxtFile(len(filenames))

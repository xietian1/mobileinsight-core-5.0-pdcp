#ifndef __DM_COLLECTOR_C_CONSTS_H__
#define __DM_COLLECTOR_C_CONSTS_H__

#include <map>
#include <string>

typedef std::map<std::string, int> StringValue;

enum LogPacketType {
    WCDMA_CELL_ID = 0x4127,
    WCDMA_Signaling_Messages = 0x412F,
    LTE_RRC_OTA_Packet = 0xB0C0,
    LTE_RRC_MIB_Message_Log_Packet = 0xB0C1,
    LTE_RRC_Serv_Cell_Info_Log_Packet = 0xB0C2,
    LTE_NAS_ESM_Plain_OTA_Incoming_Message = 0xB0E2,
    LTE_NAS_ESM_Plain_OTA_Outgoing_Message = 0xB0E3,
    LTE_NAS_EMM_Plain_OTA_Incoming_Message = 0xB0EC,
    LTE_NAS_EMM_Plain_OTA_Outgoing_Message = 0xB0ED,
    LTE_ML1_Connected_Mode_LTE_Intra_Freq_Meas_Results = 0xB179,
    LTE_ML1_IRAT_Measurement_Request = 0xB187,
    LTE_ML1_Serving_Cell_Measurement_Result = 0xB193,
    LTE_ML1_Connected_Mode_Neighbor_Meas_Req_Resp = 0xB195
};

const StringValue LogPacketType_To_ID = {
    {"WCDMA_CELL_ID",
        WCDMA_CELL_ID},
    {"WCDMA_Signaling_Messages",
        WCDMA_Signaling_Messages},
    {"LTE_RRC_OTA_Packet",
        LTE_RRC_OTA_Packet},
    {"LTE_RRC_MIB_Message_Log_Packet",
        LTE_RRC_MIB_Message_Log_Packet},
    {"LTE_RRC_Serv_Cell_Info_Log_Packet",
        LTE_RRC_Serv_Cell_Info_Log_Packet},
    {"LTE_NAS_ESM_Plain_OTA_Incoming_Message",
        LTE_NAS_ESM_Plain_OTA_Incoming_Message},
    {"LTE_NAS_ESM_Plain_OTA_Outgoing_Message",
        LTE_NAS_ESM_Plain_OTA_Outgoing_Message},
    {"LTE_NAS_EMM_Plain_OTA_Incoming_Message",
        LTE_NAS_EMM_Plain_OTA_Incoming_Message},
    {"LTE_NAS_EMM_Plain_OTA_Outgoing_Message",
        LTE_NAS_EMM_Plain_OTA_Outgoing_Message},
    {"LTE_ML1_Connected_Mode_LTE_Intra_Freq_Meas_Results",
        LTE_ML1_Connected_Mode_LTE_Intra_Freq_Meas_Results},
    {"LTE_ML1_IRAT_Measurement_Request",
        LTE_ML1_IRAT_Measurement_Request},
    {"LTE_ML1_Serving_Cell_Measurement_Result",
        LTE_ML1_Serving_Cell_Measurement_Result},
    {"LTE_ML1_Connected_Mode_Neighbor_Meas_Req_Resp",
        LTE_ML1_Connected_Mode_Neighbor_Meas_Req_Resp}
};

#endif	// __DM_COLLECTOR_C_CONSTS_H__
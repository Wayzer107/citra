// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/archives.h"
#include "core/hle/service/am/am_net.h"

namespace Service::AM {

AM_NET::AM_NET(std::shared_ptr<Module> am) : Module::Interface(std::move(am), "am:net", 5) {
    static const FunctionInfo functions[] = {
        // clang-format off
        {0x0001, &AM_NET::GetNumPrograms, "GetNumPrograms"},
        {0x0002, &AM_NET::GetProgramList, "GetProgramList"},
        {0x0003, &AM_NET::GetProgramInfos, "GetProgramInfos"},
        {0x0004, &AM_NET::DeleteUserProgram, "DeleteUserProgram"},
        {0x0005, &AM_NET::GetProductCode, "GetProductCode"},
        {0x0006, nullptr, "GetStorageId"},
        {0x0007, &AM_NET::DeleteTicket, "DeleteTicket"},
        {0x0008, &AM_NET::GetNumTickets, "GetNumTickets"},
        {0x0009, &AM_NET::GetTicketList, "GetTicketList"},
        {0x000A, nullptr, "GetDeviceID"},
        {0x000B, nullptr, "GetNumImportTitleContexts"},
        {0x000C, nullptr, "GetImportTitleContextList"},
        {0x000D, nullptr, "GetImportTitleContexts"},
        {0x000E, nullptr, "DeleteImportTitleContext"},
        {0x000F, nullptr, "GetNumImportContentContexts"},
        {0x0010, nullptr, "GetImportContentContextList"},
        {0x0011, nullptr, "GetImportContentContexts"},
        {0x0012, nullptr, "DeleteImportContentContexts"},
        {0x0013, &AM_NET::NeedsCleanup, "NeedsCleanup"},
        {0x0014, nullptr, "DoCleanup"},
        {0x0015, nullptr, "DeleteAllImportContexts"},
        {0x0016, nullptr, "DeleteAllTemporaryPrograms"},
        {0x0017, nullptr, "ImportTwlBackupLegacy"},
        {0x0018, nullptr, "InitializeTitleDatabase"},
        {0x0019, nullptr, "QueryAvailableTitleDatabase"},
        {0x001A, nullptr, "CalcTwlBackupSize"},
        {0x001B, nullptr, "ExportTwlBackup"},
        {0x001C, nullptr, "ImportTwlBackup"},
        {0x001D, nullptr, "DeleteAllTwlUserPrograms"},
        {0x001E, nullptr, "ReadTwlBackupInfo"},
        {0x001F, nullptr, "DeleteAllExpiredUserPrograms"},
        {0x0020, nullptr, "GetTwlArchiveResourceInfo"},
        {0x0021, &AM_NET::GetPersonalizedTicketInfoList, "GetPersonalizedTicketInfoList"},
        {0x0022, nullptr, "DeleteAllImportContextsFiltered"},
        {0x0023, &AM_NET::GetNumImportTitleContextsFiltered, "GetNumImportTitleContextsFiltered"},
        {0x0024, &AM_NET::GetImportTitleContextListFiltered, "GetImportTitleContextListFiltered"},
        {0x0025, &AM_NET::CheckContentRights, "CheckContentRights"},
        {0x0026, nullptr, "GetTicketLimitInfos"},
        {0x0027, nullptr, "GetDemoLaunchInfos"},
        {0x0028, nullptr, "ReadTwlBackupInfoEx"},
        {0x0029, nullptr, "DeleteUserProgramsAtomically"},
        {0x002A, nullptr, "GetNumExistingContentInfosSystem"},
        {0x002B, nullptr, "ListExistingContentInfosSystem"},
        {0x002C, &AM_NET::GetProgramInfosIgnorePlatform, "GetProgramInfosIgnorePlatform"},
        {0x002D, &AM_NET::CheckContentRightsIgnorePlatform, "CheckContentRightsIgnorePlatform"},
        {0x0401, nullptr, "UpdateFirmwareTo"},
        {0x0402, &AM_NET::BeginImportProgram, "BeginImportProgram"},
        {0x0403, nullptr, "BeginImportProgramTemporarily"},
        {0x0404, nullptr, "CancelImportProgram"},
        {0x0405, &AM_NET::EndImportProgram, "EndImportProgram"},
        {0x0406, nullptr, "EndImportProgramWithoutCommit"},
        {0x0407, nullptr, "CommitImportPrograms"},
        {0x0408, &AM_NET::GetProgramInfoFromCia, "GetProgramInfoFromCia"},
        {0x0409, &AM_NET::GetSystemMenuDataFromCia, "GetSystemMenuDataFromCia"},
        {0x040A, &AM_NET::GetDependencyListFromCia, "GetDependencyListFromCia"},
        {0x040B, &AM_NET::GetTransferSizeFromCia, "GetTransferSizeFromCia"},
        {0x040C, &AM_NET::GetCoreVersionFromCia, "GetCoreVersionFromCia"},
        {0x040D, &AM_NET::GetRequiredSizeFromCia, "GetRequiredSizeFromCia"},
        {0x040E, nullptr, "CommitImportProgramsAndUpdateFirmwareAuto"},
        {0x040F, nullptr, "UpdateFirmwareAuto"},
        {0x0410, &AM_NET::DeleteProgram, "DeleteProgram"},
        {0x0411, nullptr, "GetTwlProgramListForReboot"},
        {0x0412, &AM_NET::GetSystemUpdaterMutex, "GetSystemUpdaterMutex"},
        {0x0413, &AM_NET::GetMetaSizeFromCia, "GetMetaSizeFromCia"},
        {0x0414, &AM_NET::GetMetaDataFromCia, "GetMetaDataFromCia"},
        {0x0415, nullptr, "CheckDemoLaunchRights"},
        {0x0416, nullptr, "GetInternalTitleLocationInfo"},
        {0x0417, nullptr, "PerpetuateAgbSaveData"},
        {0x0418, nullptr, "BeginImportProgramForOverWrite"},
        {0x0419, nullptr, "BeginImportSystemProgram"},
        {0x0801, &AM_NET::BeginImportTicket, "BeginImportTicket"},
        {0x0802, nullptr, "CancelImportTicket"},
        {0x0803, &AM_NET::EndImportTicket, "EndImportTicket"},
        {0x0804, nullptr, "BeginImportTitle"},
        {0x0805, nullptr, "StopImportTitle"},
        {0x0806, nullptr, "ResumeImportTitle"},
        {0x0807, nullptr, "CancelImportTitle"},
        {0x0808, nullptr, "EndImportTitle"},
        {0x0809, nullptr, "CommitImportTitles"},
        {0x080A, nullptr, "BeginImportTmd"},
        {0x080B, nullptr, "CancelImportTmd"},
        {0x080C, nullptr, "EndImportTmd"},
        {0x080D, nullptr, "CreateImportContentContexts"},
        {0x080E, nullptr, "BeginImportContent"},
        {0x080F, nullptr, "StopImportContent"},
        {0x0810, nullptr, "ResumeImportContent"},
        {0x0811, nullptr, "CancelImportContent"},
        {0x0812, nullptr, "EndImportContent"},
        {0x0813, nullptr, "GetNumCurrentImportContentContexts"},
        {0x0814, nullptr, "GetCurrentImportContentContextList"},
        {0x0815, nullptr, "GetCurrentImportContentContexts"},
        {0x0816, nullptr, "Sign"},
        {0x0817, nullptr, "Verify"},
        {0x0818, nullptr, "GetDeviceCert"},
        {0x0819, nullptr, "ImportCertificates"},
        {0x081A, nullptr, "ImportCertificate"},
        {0x081B, nullptr, "CommitImportTitlesAndUpdateFirmwareAuto"},
        {0x081C, nullptr, "DeleteTicketId"},
        {0x081D, nullptr, "GetNumTicketIds"},
        {0x081E, nullptr, "GetTicketIdList"},
        {0x081F, nullptr, "GetNumTicketsOfProgram"},
        {0x0820, nullptr, "ListTicketInfos"},
        {0x0821, nullptr, "GetRightsOnlyTicketData"},
        {0x0822, nullptr, "GetNumCurrentContentInfos"},
        {0x0823, nullptr, "FindCurrentContentInfos"},
        {0x0824, nullptr, "ListCurrentContentInfos"},
        {0x0825, nullptr, "CalculateContextRequiredSize"},
        {0x0826, nullptr, "UpdateImportContentContexts"},
        {0x0827, nullptr, "DeleteAllDemoLaunchInfos"},
        {0x0828, nullptr, "BeginImportTitleForOverWrite"},
        // clang-format on
    };
    RegisterHandlers(functions);
}

} // namespace Service::AM

SERIALIZE_EXPORT_IMPL(Service::AM::AM_NET)

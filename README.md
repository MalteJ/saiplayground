# saiplayground

This code is run on an Accton-AS5835-54X with ecSONiC (SONiC.Edgecore-SONiC_20230505_014148_ec202111_386). Additionally [libsaibcm_8.4.0.2](https://sonicstorage.blob.core.windows.net/public/sai/sai-broadcom/SAI_8.4.0_GA/8.4.0.2/xgs/libsaibcm_8.4.0.2_amd64.deb) and [libsaibcm-dev_8.4.0.2](https://sonicstorage.blob.core.windows.net/public/sai/sai-broadcom/SAI_8.4.0_GA/8.4.0.2/xgs/libsaibcm-dev_8.4.0.2_amd64.deb) have been installed.

    # make run
    ./target/supersai
    sai_api_initialize()... SUCCESS
    sai_api_query()... SUCCESS
    create_switch()... ss_get_next_value called. ProfileID: 0
    ss_get_next_value called. ProfileID: 0
    <nounit>:ngknet_dev_ver_check: IOCTL failed on /dev/linux_ngknet
    <nounit>:bcma_sys_probe_ngbde: Unable to attach KNET driver
    Found 0 devices.
    linux-user-bde:new probed device unit 0 dev_no 0 _ndevices 1
    DMA pool size: 33554432 bytes.
    BDE dev 0 (PCI), Dev 0xb771, Rev 0x01, Chip BCM56771_A0, Driver BCM56770_A0
    SOC unit 0 attached to PCI device BCM56771_A0
    rc: unit 0 device BCM56771_A0
    0:soc_maverick2_chip_reset: TS_PLL locked on unit 0 using 50.0MHz external reference clock
    Recommended to add "ptp_ts_pll_fref=50000000" config variable
    0:soc_maverick2_chip_reset: BS_PLL0 locked on unit 0 using 50.0MHz external reference clock
    Recommended to add "ptp_bs_fref_0=50000000" config variable
    0:soc_maverick2_chip_reset: BS_PLL1 locked on unit 0 using 50.0MHz external reference clock
    Recommended to add "ptp_bs_fref_1=50000000" config variable
    <nounit>:soc_knet_check_version: KNET check version fail rv -1 version 12 netif_max 128 filter_max 1024
    0:soc_knet_init: knet version check failed rv -1
    soc_knet_handle_rx: unhandled (type=3, opcode=31)
    0:soc_dma_attach: Failed to initialize KNET: rv=-11
    M0: Error: M0 Firmware file not found!!
    UNIT0 CANCUN:
        CIH: LOADED
        Ver: 04.11.00

        CMH: LOADED
        Ver: 04.11.00
        SDK Ver: 06.05.27

        CCH: LOADED
        Ver: 04.11.00
        SDK Ver: 06.05.27

        CEH: LOADED
        Ver: 04.11.00
        SDK Ver: 06.05.27

    rc: MMU initialized
    *** unit 0: ports capable of limited speed range cut-thru
    0:_bcm_modules_init: bcm_init failed in stat
    INIT: Unable to initialize BCM driver on unit 0: Invalid configuration
    Error: failed to initialize switch, status=1
    make: *** [Makefile:19: run] Error 255

### License
Licensed under [Apache v2.0](LICENSE)
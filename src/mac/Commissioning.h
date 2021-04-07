/*
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2015 Semtech

Description: End device commissioning parameters

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Miguel Luis and Gregory Cristian
*/
#ifndef __LORA_COMMISSIONING_H__
#define __LORA_COMMISSIONING_H__

extern "C"
{
	/**@brief Define your region here 
 * Required because each region has different regulations
 * The LoRa Alliance offers documentation for the regional parameters
 * Latest revision when this library was created
 * https://lora-alliance.org/resource-hub/lorawanr-regional-parameters-v11rb 
 * Check https://lora-alliance.org/resource-hub for any updates
 * 
 * Choose a matching region from below
 * REGION_AS923 -> Asia 923 MHz
 * REGION_AU915 -> Australia 915 MHz
 * REGION_CN470 -> China 470 MHz
 * REGION_CN779 -> China 779 MHz
 * REGION_EU433 -> Europe 433 MHz
 * REGION_EU868 -> Europe 868 MHz
 * REGION_IN865 -> India 865 MHz
 * REGION_KR920 -> Korea 920 MHz
 * REGION_US915 -> US 915 MHz
 */

// For transistion time from the old library (region specific) to the new library (support of all regions)
// We throw an error here if any REGION is defined.
#if defined(REGION_AS923) || defined(REGION_AU915) || defined(REGION_CN470) || defined(REGION_CN779) || defined(REGION_EU433) || defined(REGION_EU868) || defined(REGION_IN865) || defined(REGION_KR920) || defined(REGION_US915) || defined(REGION_US915_HYBRID)
#error "SX126x-Arduino V2.0 does support all LoRaWAN regions without definition of 'REGION_XXYYY. Please read detailed information how to use it on https://github.com/beegee-tokyo/SX126x-Arduino/blob/master/README_V2.md"
#endif

// #if !defined(REGION_AS923) && !defined(REGION_AU915) && !defined(REGION_CN470) && !defined(REGION_CN779) && !defined(REGION_EU433) && !defined(REGION_EU868) && !defined(REGION_IN865) && !defined(REGION_KR920) && !defined(REGION_US915) && !defined(REGION_US915_HYBRID)
// #define REGION_US915
// #endif

#define REGION_AS923
#define REGION_AU915
#define REGION_CN470
#define REGION_CN779
#define REGION_EU433
#define REGION_EU868
#define REGION_IN865
#define REGION_KR920
#define REGION_US915
#define REGION_US915_HYBRID

/**@brief Enable or disable duty cycle control
 * LoRaWAN ETSI duty cycle control enable/disable. 
 * Please note that ETSI mandates duty cycled transmissions. 
 * Use only for test purposes
 */
#define LORAWAN_DUTYCYCLE_ON true	/**< LoRaWAN duty cycle enabled */
#define LORAWAN_DUTYCYCLE_OFF false /**< LoRaWAN duty cycle disabled */

/**@brief Indicates if the end-device is to be connected to a private or public network
 */
#define LORAWAN_PUBLIC_NETWORK true	 /**< LoRaWAN public network */
#define LORAWAN_PRIVAT_NETWORK false /**< LoRaWAN private network */

/**@brief Enable or disable LoRaWAN Adaptive Data Rate enabled (the end-device should be static here).
 */
#define LORAWAN_ADR_ON true	  /**< LoRaWAN Adaptive Data Rate enabled (the end-device should be static here). */
#define LORAWAN_ADR_OFF false /**< LoRaWAN Adaptive Data Rate disabled. */

/**@brief Select if a hard coded device ID is used or an automatic generated one
 * When set to 1 DevEui is LORAWAN_DEVICE_EUI
 * When set to 0 DevEui is automatically generated by calling BoardGetUniqueId function
 */
#define STATIC_DEVICE_EUI 1

/**@brief Mote device IEEE EUI (big endian)
 *
 * @remark see STATIC_DEVICE_EUI comments
 */
#define LORAWAN_DEVICE_EUI                             \
	{                                                  \
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 \
	}

/**@brief Application IEEE EUI (big endian)
 */
#define LORAWAN_APPLICATION_EUI                        \
	{                                                  \
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 \
	}

/**@brief AES encryption/decryption cipher application key
 */
#define LORAWAN_APPLICATION_KEY                                                                        \
	{                                                                                                  \
		0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C \
	}

/**@brief Current network ID
 */
#define LORAWAN_NETWORK_ID (uint32_t)0

/**@brief Select if a hard coded device address is used or an automatic generated one
 * When set to 1 DevAdd is LORAWAN_DEVICE_ADDRESS
 * When set to 0 DevAdd is automatically generated using
 *         a pseudo random generator seeded with a value derived from
 *         BoardUniqueId value
 */
#define STATIC_DEVICE_ADDRESS 1

/**@brief Device address on the network (big endian)
 *
 * @remark In this application the value is automatically generated using
 *         a pseudo random generator seeded with a value derived from
 *         BoardUniqueId value if LORAWAN_DEVICE_ADDRESS is set to 0
 */
#define LORAWAN_DEVICE_ADDRESS (uint32_t)0x00000000

/**@brief AES encryption/decryption cipher network session key
 */
#define LORAWAN_NWKSKEY                                                                                \
	{                                                                                                  \
		0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C \
	}

/**@brief AES encryption/decryption cipher application session key
 */
#define LORAWAN_APPSKEY                                                                                \
	{                                                                                                  \
		0x2B, 0x7E, 0x15, 0x16, 0x28, 0xAE, 0xD2, 0xA6, 0xAB, 0xF7, 0x15, 0x88, 0x09, 0xCF, 0x4F, 0x3C \
	}
};
#endif // __LORA_COMMISSIONING_H__

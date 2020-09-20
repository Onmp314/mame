// license:BSD-3-Clause
// copyright-holders:Guru, Scott Stone, Onmp314
/***************************************************************************

Konami (Bemani) Python (2) Hardware Overview
Konami 2002-2007

Onmp314 notes:
Konami Python 2 is based on a fat PS2, but with an 
additional I/O board and (possibly) a different BIOS. 
The first games on this equipment appeared at the turn of 2004/2005.

This system uses a standard GH-006 PS2 main board (the older Playstation 2 square type) with a
Sony-supplied PS2 power supply which bolts onto the top of the main board. This power supply
has a single 12 volt power input and creates all of the voltages for the PS2. The same 12 volt input
extends via a splitter to the Konami interface PCB into CN3. The PS2 main board is connected to the
custom Konami interface PCB via the PS2 main board AV connector and the IEEE 1394 'i.LINK' connector.
A security dongle with no label on the top which looks like a PS2 memory card is plugged into the left
PS2 memory card slot. This card is identical to the dongles used in Namco System 246/256. Note that the
two games dumped so far have the same label on the security dongle (KN00002) but the ROM inside is not
identical. So far all the Konami game software resides on a 128M CF card. However there are probably
HDD/CDROM/DVDROM-based games too since the Konami interface board has connectors for IDE drives.

Games known to run on this system include....                      DIN5
                                                       CF Card     Dongle                 PS2 Cart
Game Title                                             Label       Label                  Label (bottom)
---------------------------------------------------------------------------------------------------------
*Baseball Heroes 2005
*Battle Climaxx!
*Battle Climaxx! 2
*Dance 86.4 Funky Radio Station (Bemani Python 2)
*Dance Dance Revolution SuperNOVA (Bemani Python 2)
*Dance Dance Revolution SuperNOVA 2 (Bemani Python 2)
*Drum Mania V (Bemani Python 2)
*Drum Mania V2 (Bemani Python 2)
*Drum Mania V3 (Bemani Python 2)
*Dancing Stage Fusion (Bemani Python 1)
*Dog Station
*Dog Station Deluxe
*Guitar Freaks V (Bemani Python 2)
*Guitar Freaks V2 (Bemani Python 2)
*Guitar Freaks V3 (Bemani Python 2)
*Monster Gate Online
*Monster Gate Online 2
*Nice Smash!
*Paintball Mania
*Perfect Pool
*Pool Pocket Fortunes
Pop'n Music 9 (Bemani Python 1)
*Pop'n Music 10 (Bemani Python 2 (?))
*Pop'n Music 11 (Bemani Python 2 (?))
*Pop'n Music 12 Iroha (Bemani Python 2 (?))
*Pop'n Music 13 Carnival (Bemani Python 2 (?))
*Pop'n Music 14 Fever! (Bemani Python 2 (?))
*R.P.M. Red
*Thrill Drive 3 (Python 2)
*Toy's March (Bemani Python 2)
*Toy's March 2 (Bemani Python 2)
World Soccer Winning Eleven Arcade Game Style          C18JAA03    DIN5 dongle GCC27JA    KN00002
World Soccer Winning Eleven Arcade Game Style 2003     C27JAA03    not used               KN00002
---------------------------------------------------------------------------------------------------------

* denotes not dumped.

Konami PCB Layout
-----------------

PWB0000106626
KONAMI 2002
  |-----------------------------------------|
  |          CN5  CN7  CN2               CN3|
|-|                                         |
|   TD62064        LM358   |------|  BA7078 |
|               3793       |VS218 |  25MHz  |
|      056879      LM358   |      |      CN9|
|J                         |------|     LED3|
|A                                      LED4|
|M                 LM358       D72872GC LED5|
|M                                 24MHz    |
|A     ADC0838     6379                 CN12|
|        LM358                              |
|                                           |
|  LED6-13                              CN13|
|-|                                         |
  |                    |--------|           |
  |                    |TOSHIBA |           |
|-|                    |TMPR3927|           |
|    DS14C232          |        |           |
|                      |--------|           |
|                  8.4MHz                   |
|C                                          |
|N               48LC2M32B2                 |
|1                                  CN16    |
|5       XC9536   B22A01.U42            CN17|
|                           XCS10XL         |
|                M48T58Y.U48                |
|                            DS2430         |
|       DS14C232                            |
|-|                                         |
  |SW4   CN19     CN20           CN21       |
  |-----------------------------------------|
Notes:
      LM358      - National LM358 Dual Operational Amplifier (SOIC8)
      6379       - NEC uPD6379A 2-Channel 16-bit D/A Cconverter (SOIC8)
      3793       - Fujitsu MB3793-A Power Voltage Monitoring IC with Watchdog Timer (SOIC8)
      TD62064    - Toshiba TDA62064 Darlington Transistor Array
      BA7078     - ROHM BA7078 Sync Separator / Sync Detection IC (SOIC18)
      VS218      - National VS218ALC4 (video-related?) (TQFP144)
      D72872GC   - NEC D72872GC IEEE 1394 controller (TQFP120)
      056879     - Konami custom 056879 (QFP120)
      ADC0838    - National ADC0838 8-Bit Serial I/O A/D Converter with Multiplexer Option (SOIC20)
      DS14C232   - National DS14C232 Low Power +5V Powered TIA/EIA-232 Dual Driver/Receiver (SOIC16)
      TMPR3927   - Toshiba TMPR3927 32-bit R3000A-based RISC micro-controller (QFP240)
      48LC2M32B2 - Micron 48LC2M32B2 512k x32-bit x4-banks (64MBit) SDRAM (TSOP86)
      XC9536     - Xilinx XC9536XL CPLD stamped 'QB22A1' (PLCC44)
      B22A01.U42 - Fujitsu MBM29F400 512k x8-bit flash ROM stamped 'B22A01' (TSOP48). This is probably
                   the common-to-all-games Pyson BIOS for the TMPR3927
      XCS10XL    - Xilinx Spartan XCS10XL FPGA (TQFP144)
      M48T58Y    - ST Microelectronics M48T58Y 8k Timekeeper/NVRAM (DIP28). As well as being used for protection
                   with the Konami game code/year etc (the usual first 16 bytes) it also seems to contain code
                   or other data in some of the games, meaning it's not possible to hand-create the NVRAMs.
                   The same 'extended usage' of this chip is also present on Konami Viper PCBs.
      DS2430     - Dallas DS2430 256-bit EEPROM and silicon serial number (3 pin TO-92 package)
      CN2        - RJ45 network connector
      CN3        - 5 pin power input connector (12 volts only)
      CN5/7      - RCA jacks for unamplified stereo audio output
      CN9        - 13 pin audio/video connector joined with a cable to the PS2 main board AV connector
      CN12       - IEEE 1394 connector joined with a cable to the PS2 main board 'i.LINK' connector
      CN13       - 4 pin power connector (unused)
      CN15       - 28 way edge connector which connects to the filter board along with the JAMMA edge connector
      CN16       - 40 pin standard IDE connector (for CDROM/DVDROM or 3.5" IDE HDD)
      CN17       - 44 pin standard IDE connector (for 2.5" IDE HDD)
      CN19       - DIN5 connector for plug-in security module. The module contains a Dallas DS2430 which
                   effectively replaces the common-to-most-games one on the main board (same a Viper h/w)
      CN20       - 4 pin connector
      CN21       - Standard Compact Flash card slot
      SW4        - 4 position DIP switch


Filter Board
------------

This plugs into the Konami interface board at 90 degrees via the 2x 28-way female connectors
All components face the Konami interface PCB. Only the JVS power connectors, JAMMA and CN* are externally accessible.

PWB0000121667 2002 KONAMI
|----------------------------|      |------------------------------|
|   CN4   CN5  CN7     CN14  |------|            JAMMA             |------|
|                                                                         |
|               LMH6643 DS485                                     8PIN_JVS|
|   HD64F3664   XC9536                                                    |
|CN1  14MHz                                                               |
|               LMH6643                                 TPC8013   6PIN_JVS|
|                                                                         |
|         28-WAY-FEMALE                      28-WAY-FEMALE                |
|-------------------------------------------------------------------------|
Notes:
      CN4      - 8-pin mini-DIN connector
      CN5/7    - 15-pin VGA connectors
      CN14     - Standard USB connector. This connects to a standard JVS I/O board. It was tested with
                 a common Sega JVS I/O and works fine however Konami probably have their own JVS I/O board
                 for use with this system
     HD64F3664 - Hitachi HD64F3664 H8/3664 micro-controller stamped 'C18B6' or 'C18A6' (QFP64)
     XC9536    - Xilinx XC9536 CPLD stamped 'EC18B1' (PLCC44)
     DS485     - National DS485 Low-Power Transceiver for RS-485 and RS-422 Communication (SOIC8)
     LMH6643   - National LMH6643 3V, Low Power, 130MHz, 75mA Rail-to-Rail Output Amplifier (SOIC8)
     TPC8013   - Toshiba TPC8013 Silicon N Channel MOS Type Field Effect Transistor (SOIC8)
     28-WAY*   - 28-Way Female connectors. These both plug into the Konami interface board
     JAMMA     - Standard Jamma Edge Connector (not used)
     8PIN_JVS  - Common JVS Power Connectors (on other side of the PCB)
     6PIN_JVS  /

***************************************************************************/


#include "emu.h"
#include "cpu/mips/mips3.h"
#include "cpu/mips/mips1.h"
#include "emupal.h"
#include "screen.h"


class python_state : public driver_device
{
public:
	python_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag),
			m_maincpu(*this, "maincpu")
	{ }

	void python(machine_config &config);

private:
	uint32_t screen_update(screen_device &screen, bitmap_rgb32 &bitmap, const rectangle &cliprect);

	void ps2_map(address_map &map);

	// devices
	required_device<mips3_device> m_maincpu;

	// driver_device overrides
	virtual void video_start() override;
};


void python_state::video_start()
{
}

uint32_t python_state::screen_update(screen_device &screen, bitmap_rgb32 &bitmap, const rectangle &cliprect)
{
	return 0;
}

void python_state::ps2_map(address_map &map)
{
	map(0x00000000, 0x01ffffff).ram(); // 32 MB RAM in consumer PS2s, do these have more?
	map(0x1fc00000, 0x1fdfffff).rom().region("bios", 0);
}

static INPUT_PORTS_START( python )
INPUT_PORTS_END

void python_state::python(machine_config &config)
{
	R5000LE(config, m_maincpu, 294000000); // imported from namcops2.c driver
	m_maincpu->set_icache_size(16384);
	m_maincpu->set_dcache_size(16384);
	m_maincpu->set_addrmap(AS_PROGRAM, &python_state::ps2_map);

	/* video hardware */
	screen_device &screen(SCREEN(config, "screen", SCREEN_TYPE_RASTER));
	screen.set_refresh_hz(60);
	screen.set_screen_update(FUNC(python_state::screen_update));
	screen.set_size(640, 480);
	screen.set_visarea(0, 639, 0, 479);

	PALETTE(config, "palette").set_entries(65536);
}

#define PYTHON_BIOS  \
		ROM_LOAD( "b22a01.u42", 0x000000, 0x080000, CRC(98de405e) SHA1(4bc268a996825c1bdf6ae277d331fe7bdc0cc00c) )

ROM_START( python )
	ROM_REGION32_LE(0x200000, "bios", 0)
	PYTHON_BIOS

	ROM_REGION(0x840000, "key", ROMREGION_ERASE00)
	DISK_REGION( "ide:0:hdd:image" )
ROM_END

ROM_START( wswe )
	ROM_REGION32_LE(0x200000, "bios", 0)
	PYTHON_BIOS

	ROM_REGION(0x840000, "key", ROMREGION_ERASE00)
		ROM_LOAD( "kn00002.ic002",     0x000000, 0x800000, CRC(bd1770aa) SHA1(be217d6d7648e529953ea25caad904394919644c) )
		ROM_LOAD( "kn00002_spr.ic002", 0x800000, 0x040000, CRC(296c8436) SHA1(c0da440b50dba4ca8eb2b1ee7b6de681769fcf65) )

	ROM_REGION(0x2000, "timekeeper", ROMREGION_ERASE00)
		ROM_LOAD( "m48t58y.u48",       0x000000, 0x002000, CRC(d4181cb5) SHA1(c5560d1ac043bfe2527fac3fb1989fa8fc53cf8a) )

	DISK_REGION( "ide:0:hdd:image" )
	DISK_IMAGE_READONLY( "c18jaa03", 0, SHA1(b47190aa38f1f3a499b817758e3f29fac54391bd) )
ROM_END

ROM_START( wswe2k3 )
	ROM_REGION32_LE(0x200000, "bios", 0)
	PYTHON_BIOS

	ROM_REGION(0x840000, "key", ROMREGION_ERASE00)
		ROM_LOAD( "kn00002.ic002",     0x000000, 0x800000, CRC(6f5b7309) SHA1(5e9d75497c3a3a92af41b20e41991c9c5837d50a) )
		ROM_LOAD( "kn00002_spr.ic002", 0x800000, 0x040000, CRC(433f7ad9) SHA1(4fd05124d59cdbedd781580e49ff940c5df67d94) )

	ROM_REGION(0x2000, "timekeeper", ROMREGION_ERASE00)
		ROM_LOAD( "m48t58y.u48",       0x000000, 0x002000, CRC(76068de0) SHA1(5f75b88ad04871fb3799fe904658c87524bad94f) )

	DISK_REGION( "ide:0:hdd:image" )
	DISK_IMAGE_READONLY( "c27jaa03", 0, SHA1(9b2aa900711d88cf5effb3ba6be18726ea006ac4) )
ROM_END


// Konami Python (1st generation)

GAME(2002, python,          0,   python,   python, python_state, empty_init, ROT0, "Konami", "Konami Python BIOS", MACHINE_IS_SKELETON|MACHINE_IS_BIOS_ROOT)
// GAME(2005, basher05,          0,   python,   python, python_state, empty_init, ROT0, "Konami", "Baseball Heroes 2005", MACHINE_IS_SKELETION) /* undumped, satelite */
// GAME(2004, batcm,         0,   python,   python, python_state, empty_init, ROT0, "Konami", "Battle Climaxx!", MACHINE_IS_SKELETION) /* undumped, satelite */
// GAME(2005, batcm2,        0,   python,   python, python_state, empty_init, ROT0, "Konami", "Battle Climaxx! 2", MACHINE_IS_SKELETION) /* undumped, satelite */
// GAME(2005, dsfs,         0,   python,   python, python_state, empty_init, ROT0, "Konami", "Dancing Stage Fusion (Europe)", MACHINE_IS_SKELETION) /* undumped, Bemani Python 1 */
// GAME(2002, dogst,        0,   python,   python, python_state, empty_init, ROT0, "Konami", "Dog Station", MACHINE_IS_SKELETION) /* undumped, requires keyboard */
// GAME(2002, dogstdx,        0,   python,   python, python_state, empty_init, ROT0, "Konami", "Dog Station Deluxe", MACHINE_IS_SKELETION) /* undumped, requires keyboard */
// GAME(2004, monsron,        0,   python,   python, python_state, empty_init, ROT0, "Konami", "Monster Gate Online", MACHINE_IS_SKELETION) /* undumped, satelite */
// GAME(2005, monsron2,        0,   python,   python, python_state, empty_init, ROT0, "Konami", "Monster Gate Online 2", MACHINE_IS_SKELETION) /* undumped, satelite */
// GAME(2002, nicesm,        0,   python,   python, python_state, empty_init, ROT0, "Konami", "Nice Smash!", MACHINE_IS_SKELETION) /* undumped */
// GAME(2005, paiblmn        0,   python,   python, python_state, empty_init, ROT0, "Konami", "Paintball Mania", MACHINE_IS_SKELETION)	/* undumped */
// GAME(2002, perpool        0,   python,   python, python_state, empty_init, ROT0, "Konami", "Perfect Pool", MACHINE_IS_SKELETION) /* undumped, mechanical parts? */
// GAME(2002, poolpf        0,   python,   python, python_state, empty_init, ROT0, "Konami", "Pool Pocket Fortunes", MACHINE_IS_SKELETION) /* undumped */
// GAME(2003, popn9        0,   python,   python, python_state, empty_init, ROT0, "Konami", "Pop'n Music 9", MACHINE_IS_SKELETION) /* TODO: move from viper.cpp, Bemani Python 1 */
// GAME(2003, rpmred        0,   python,   python, python_state, empty_init, ROT0, "Konami", "R.P.M. Red", MACHINE_IS_SKELETION) /* undumped, satelite */	
GAME(2002, wswe,       python,   python,   python, python_state, empty_init, ROT0, "Konami", "World Soccer Winning Eleven Arcade Game Style (Japan?)", MACHINE_IS_SKELETON)
GAME(2003, wswe2k3,    python,   python,   python, python_state, empty_init, ROT0, "Konami", "World Soccer Winning Eleven Arcade Game 2003 (Japan?)", MACHINE_IS_SKELETON)
	
// Konami Python (2nd generation)

// GAME(2004?, python2,          0,   python,   python, python_state, empty_init, ROT0, "Konami", "Konami Python 2 BIOS", MACHINE_IS_SKELETON|MACHINE_IS_BIOS_ROOT) /* undumped, perhaps Python 2 is based on Python BIOS */	

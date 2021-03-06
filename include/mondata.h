/*	SCCS Id: @(#)mondata.h	3.4	2003/01/08	*/
/* Copyright (c) 1989 Mike Threepoint				  */
/* NetHack may be freely redistributed.  See license for details. */

#ifndef MONDATA_H
#define MONDATA_H

#define verysmall(ptr)		((ptr)->msize < MZ_SMALL)
#define bigmonst(ptr)		((ptr)->msize >= MZ_LARGE)

#define pm_resistance(ptr,typ)	(((ptr)->mresists & (typ)) != 0)

//#define resists_fire(mon)	(((mon)->mintrinsics & MR_FIRE) != 0 || (mon == u.usteed && u.sealsActive&SEAL_BERITH && Fire_resistance))
// #define resists_fire(mon)	(((mon)->mintrinsics & MR_FIRE) != 0)
// #define resists_cold(mon)	(((mon)->mintrinsics & MR_COLD) != 0)
// #define resists_sleep(mon)	(((mon)->mintrinsics & MR_SLEEP) != 0)
// #define resists_disint(mon)	(((mon)->mintrinsics & MR_DISINT) != 0)
// #define resists_elec(mon)	(((mon)->mintrinsics & MR_ELEC) != 0)
// #define resists_poison(mon)	(((mon)->mintrinsics & MR_POISON) != 0)
// #define resists_acid(mon)	(((mon)->mintrinsics & MR_ACID) != 0)
// #define resists_ston(mon)	(((mon)->mintrinsics & MR_STONE) != 0)
// #define resists_drain(mon)	(((mon)->mintrinsics & MR_DRAIN) != 0)
// #define resists_sickness(mon)	(((mon)->mintrinsics & MR_SICK) != 0)

#define is_lminion(mon)		(is_minion((mon)->data) && \
				 (mon)->data->maligntyp >= A_COALIGNED && \
				 ((mon)->data != &mons[PM_ANGEL] || \
				  EPRI(mon)->shralign > 0))

#define is_flyer(ptr)		(((ptr)->mflags1 & M1_FLY) != 0L)
#define is_displacer(ptr)	((ptr) == &mons[PM_DISPLACER_BEAST] || (ptr) == &mons[PM_SHIMMERING_DRAGON])
#define is_floater(ptr)		((ptr) && (ptr)->mlet == S_EYE && !(is_auton(ptr) || ptr == &mons[PM_MONOTON]))
#define is_clinger(ptr)		(((ptr)->mflags1 & M1_CLING) != 0L)
#define is_swimmer(ptr)		(((ptr)->mflags1 & M1_SWIM) != 0L)
#define breathless(ptr)		(((ptr)->mflags1 & M1_BREATHLESS) != 0L)
#define amphibious(ptr)		(((ptr)->mflags1 & (M1_AMPHIBIOUS | M1_BREATHLESS)) != 0L)
#define passes_walls(ptr)	(((ptr)->mflags1 & M1_WALLWALK) != 0L)
#define amorphous(ptr)		(((ptr)->mflags1 & M1_AMORPHOUS) != 0L)
#define noncorporeal(ptr)	((ptr)->mlet == S_GHOST || (ptr)->mlet == S_SHADE)
#define tunnels(ptr)		(((ptr)->mflags1 & M1_TUNNEL) != 0L)
#define needspick(ptr)		(((ptr)->mflags1 & M1_NEEDPICK) != 0L)
#define hides_under(ptr)	(((ptr)->mflags1 & M1_CONCEAL) != 0L)
#define is_hider(ptr)		(((ptr)->mflags1 & M1_HIDE) != 0L)
#define haseyes(ptr)		(((ptr)->mflags1 & M1_NOEYES) == 0L)
#define eyecount(ptr)		(!haseyes(ptr) ? 0 : \
				 ((ptr) == &mons[PM_CYCLOPS] || \
				  (ptr) == &mons[PM_FLOATING_EYE]) ? 1 : 2)
#define nohands(ptr)		(((ptr)->mflags1 & M1_NOHANDS) != 0L)
#define nolimbs(ptr)		(((ptr)->mflags1 & M1_NOLIMBS) == M1_NOLIMBS)
#define notake(ptr)		(((ptr)->mflags1 & M1_NOTAKE) != 0L)
#define has_head(ptr)		(((ptr)->mflags1 & M1_NOHEAD) == 0L)
#define has_horns(ptr)		(num_horns(ptr) > 0)
#define is_whirly(ptr)		((ptr)->mlet == S_VORTEX || \
				 (ptr) == &mons[PM_AIR_ELEMENTAL] ||\
				 (ptr) == &mons[PM_ILLURIEN_OF_THE_MYRIAD_GLIMPSES] ||\
				 (ptr) == &mons[PM_DREADBLOSSOM_SWARM])
#define flaming(ptr)		((ptr) == &mons[PM_FIRE_VORTEX] || \
				 (ptr) == &mons[PM_FLAMING_SPHERE] || \
				 (ptr) == &mons[PM_FIRE_ELEMENTAL] || \
				 (ptr) == &mons[PM_SALAMANDER])
#define is_stone(ptr)	((ptr) == &mons[PM_DUST_VORTEX] || \
				 (ptr) == &mons[PM_EARTH_ELEMENTAL] || \
				 (ptr) == &mons[PM_GARGOYLE] || \
				 (ptr) == &mons[PM_WINGED_GARGOYLE] || \
				 (ptr) == &mons[PM_XORN])
#define is_anhydrous(ptr)	(flaming(ptr)  || \
							 is_clockwork(ptr) || \
							 is_stone(ptr) || \
							 is_auton(ptr) || \
				 (ptr)->mlet == S_KETER || \
				 (ptr) == &mons[PM_AOA] || \
				 (ptr) == &mons[PM_AOA_DROPLET])
#define no_innards(ptr)	((ptr)->mlet == S_VORTEX || \
						 (ptr)->mlet == S_LIGHT || \
						 (ptr)->mlet == S_ELEMENTAL || \
						 ((ptr) == &mons[PM_SHAMBLING_HORROR] && u.shambin == 2) || \
						 ((ptr) == &mons[PM_STUMBLING_HORROR] && u.stumbin == 2) || \
						 ((ptr) == &mons[PM_WANDERING_HORROR] && u.wandein == 2) || \
						 (ptr)->mlet == S_WRAITH || \
						 (ptr)->mlet == S_GHOST || \
						 (ptr)->mlet == S_SHADE || \
						 (ptr)->mlet == S_GOLEM \
						)
#define undiffed_innards(ptr)	((ptr)->mlet == S_BLOB || \
								 (ptr) == &mons[PM_FLOATING_EYE] || \
								 (ptr)->mlet == S_JELLY || \
								 (ptr)->mlet == S_TRAPPER || \
								 (ptr)->mlet == S_FUNGUS || \
								 (ptr)->mlet == S_PUDDING || \
								 ((ptr) == &mons[PM_SHAMBLING_HORROR] && u.shambin == 1) || \
								 ((ptr) == &mons[PM_STUMBLING_HORROR] && u.stumbin == 1) || \
								 ((ptr) == &mons[PM_WANDERING_HORROR] && u.wandein == 1) || \
								 (ptr)->mlet == S_PLANT \
								)
#define is_silent(ptr)		((ptr)->msound == MS_SILENT)
#define unsolid(ptr)		(((ptr)->mflags1 & M1_UNSOLID) != 0L)
#define mindless(ptr)		(((ptr)->mflags1 & M1_MINDLESS) != 0L)
#define humanoid(ptr)		(((ptr)->mflags1 & M1_HUMANOID) != 0L)
#define is_animal(ptr)		(((ptr)->mflags1 & M1_ANIMAL) != 0L)
#define slithy(ptr)		(((ptr)->mflags1 & M1_SLITHY) != 0L)
#define is_wooden(ptr)		((ptr) == &mons[PM_WOOD_GOLEM])
#define thick_skinned(ptr)	(((ptr)->mflags1 & M1_THICK_HIDE) != 0L)
#define lays_eggs(ptr)		(((ptr)->mflags1 & M1_OVIPAROUS) != 0L)
#define regenerates(ptr)	(((ptr)->mflags1 & M1_REGEN) != 0L)
#define perceives(ptr)		(((ptr)->mflags1 & M1_SEE_INVIS) != 0L)
#define can_teleport(ptr)	(((ptr)->mflags1 & M1_TPORT) != 0L)
#define control_teleport(ptr)	(((ptr)->mflags1 & M1_TPORT_CNTRL) != 0L)
#define telepathic(ptr)		((ptr) == &mons[PM_FLOATING_EYE] || \
				 (ptr) == &mons[PM_MIND_FLAYER] || \
				 (ptr) == &mons[PM_MASTER_MIND_FLAYER])
#define is_armed(ptr)		attacktype(ptr, AT_WEAP)
#define crpsdanger(ptr)		(acidic(ptr) || poisonous(ptr) ||\
							 freezing(ptr) || burning(ptr))
#define acidic(ptr)		(((ptr)->mflags1 & M1_ACID) != 0L)
#define poisonous(ptr)		(((ptr)->mflags1 & M1_POIS) != 0L)
#define freezing(ptr)		(((ptr)->mflags3 & M3_CHILL) != 0L)
#define burning(ptr)		(((ptr)->mflags3 & M3_TOSTY) != 0L)
#define carnivorous(ptr)	(((ptr)->mflags1 & M1_CARNIVORE) != 0L)
#define herbivorous(ptr)	(((ptr)->mflags1 & M1_HERBIVORE) != 0L)
#define metallivorous(ptr)	(((ptr)->mflags1 & M1_METALLIVORE) != 0L)
#define polyok(ptr)		(((ptr)->mflags2 & M2_NOPOLY) == 0L)
#define is_Rebel(ptr)		(ptr == &mons[PM_REBEL_RINGLEADER] ||\
							 ptr == &mons[PM_ADVENTURING_WIZARD] ||\
							 ptr == &mons[PM_MILITANT_CLERIC] ||\
							 ptr == &mons[PM_HALF_ELF_RANGER])
#define is_undead(ptr)		(((ptr)->mflags2 & M2_UNDEAD) != 0L)
#define is_were(ptr)		(((ptr)->mflags2 & M2_WERE) != 0L)
#define is_vampire(ptr)		(((ptr)->mflags2 & M2_VAMPIRE) != 0L)
#define is_elf(ptr)		(((ptr)->mflags2 & M2_ELF) != 0L)
#define is_drow(ptr)		(((ptr) == &mons[PM_DROW]) ||\
							 ((ptr) == &mons[PM_HEDROW_WARRIOR]) ||\
							 ((ptr) == &mons[PM_DROW_MATRON])\
							)
#define is_dwarf(ptr)		(((ptr)->mflags2 & M2_DWARF) != 0L)
#define is_gnome(ptr)		(((ptr)->mflags2 & M2_GNOME) != 0L)
#define is_orc(ptr)		(((ptr)->mflags2 & M2_ORC) != 0L)
#define is_ogre(ptr)		((ptr)->mlet == S_OGRE)
#define is_kobold(ptr)		((ptr)->mlet == S_KOBOLD)
#define is_ettin(ptr)		((ptr) == &mons[PM_ETTIN])
#define is_human(ptr)		(((ptr)->mflags2 & M2_HUMAN) != 0L)
#define is_fungus(ptr)		((ptr)->mlet == S_FUNGUS)
#define is_migo(ptr)		((ptr) == &mons[PM_MIGO_WORKER] ||\
							 (ptr) == &mons[PM_MIGO_SOLDIER] ||\
							 (ptr) == &mons[PM_MIGO_PHILOSOPHER] ||\
							 (ptr) == &mons[PM_MIGO_QUEEN])
#define your_race(ptr)		(((ptr)->mflags2 & urace.selfmask) != 0L)
#define is_andromaliable(ptr)	(is_elf(ptr) || is_dwarf(ptr) || is_gnome(ptr) || is_orc(ptr) || is_human(ptr) || (ptr) == &mons[PM_HOBBIT] || \
								 (ptr) == &mons[PM_MONKEY] || (ptr) == &mons[PM_APE] || (ptr) == &mons[PM_YETI] || \
								 (ptr) == &mons[PM_CARNIVOROUS_APE] || (ptr) == &mons[PM_SASQUATCH]\
								)
#define is_bat(ptr)		((ptr) == &mons[PM_BAT] || \
				 (ptr) == &mons[PM_GIANT_BAT] || \
				 (ptr) == &mons[PM_VAMPIRE_BAT])
#define is_social_insect(ptr) ((ptr)->mlet == S_ANT && (ptr)->maligntyp > 0)
#define is_spider(ptr) ((ptr)->mlet == S_SPIDER && (\
				 (ptr) == &mons[PM_CAVE_SPIDER]\
				 (ptr) == &mons[PM_GIANT_SPIDER]\
				 (ptr) == &mons[PM_PHASE_SPIDER]\
				 ))
#define is_rat(ptr)		((ptr) == &mons[PM_SEWER_RAT] || \
				 (ptr) == &mons[PM_GIANT_RAT] || \
				 (ptr) == &mons[PM_RABID_RAT] || \
				 (ptr) == &mons[PM_ENORMOUS_RAT] || \
				 (ptr) == &mons[PM_RODENT_OF_UNUSUAL_SIZE])
#define is_bird(ptr)		((ptr)->mlet == S_BAT && !is_bat(ptr) && (ptr) != &mons[PM_BYAKHEE])
#define is_giant(ptr)		(((ptr)->mflags2 & M2_GIANT) != 0L)
#define is_gnoll(ptr)		((ptr) == &mons[PM_GNOLL] || \
				 (ptr) == &mons[PM_GNOLL_GHOUL] || \
				 (ptr) == &mons[PM_ANUBITE] || \
				 (ptr) == &mons[PM_GNOLL_MATRIARCH] || \
				 (ptr) == &mons[PM_YEENOGHU])
#define is_minotaur(ptr)		((ptr) == &mons[PM_MINOTAUR] || \
				 (ptr) == &mons[PM_MINOTAUR_PRIESTESS] || \
				 (ptr) == &mons[PM_BAPHOMET])
#define is_pirate(ptr)		((ptr) == &mons[PM_PIRATE] || \
				 (ptr) == &mons[PM_PIRATE_BROTHER] || \
				 (ptr) == &mons[PM_SKELETAL_PIRATE] || \
				 (ptr) == &mons[PM_DAMNED_PIRATE] || \
				 (ptr) == &mons[PM_GITHYANKI_PIRATE] || \
				 (ptr) == &mons[PM_MAYOR_CUMMERBUND])
#define is_golem(ptr)		((ptr)->mlet == S_GOLEM)
#define is_clockwork(ptr)	(((ptr)->mflags2 & M2_CLOCK) != 0L)
#define is_domestic(ptr)	(((ptr)->mflags2 & M2_DOMESTIC) != 0L)
#define is_demon(ptr)		(((ptr)->mflags2 & M2_DEMON) != 0L)
#define is_keter(ptr)		((ptr)->mlet == S_KETER)
#define is_auton(ptr)		(	(ptr) == &mons[PM_MONOTON] ||\
								(ptr) == &mons[PM_DUTON] ||\
								(ptr) == &mons[PM_TRITON] ||\
								(ptr) == &mons[PM_QUATON] ||\
								(ptr) == &mons[PM_QUINON] ||\
								(ptr) == &mons[PM_AXUS]\
							)
#define is_divider(ptr)		( (ptr) == &mons[PM_BLACK_PUDDING]\
							  || (ptr) == &mons[PM_BROWN_PUDDING]\
							  || (ptr) == &mons[PM_DARKNESS_GIVEN_HUNGER]\
							  || (ptr) == &mons[PM_GREMLIN]\
							  || (ptr) == &mons[PM_DUNGEON_FERN_SPORE]\
							  || (ptr) == &mons[PM_DUNGEON_FERN_SPROUT]\
							  || (ptr) == &mons[PM_SWAMP_FERN_SPORE]\
							  || (ptr) == &mons[PM_SWAMP_FERN_SPROUT]\
							  || (ptr) == &mons[PM_RAZORVINE]\
							)
#define is_mercenary(ptr)	(((ptr)->mflags2 & M2_MERC) != 0L)
#define is_male(ptr)		(((ptr)->mflags2 & M2_MALE) != 0L)
#define is_female(ptr)		(((ptr)->mflags2 & M2_FEMALE) != 0L)
#define is_neuter(ptr)		(((ptr)->mflags2 & M2_NEUTER) != 0L)
#define is_wanderer(ptr)	(((ptr)->mflags2 & M2_WANDER) != 0L)
#define always_hostile(ptr)	(((ptr)->mflags2 & M2_HOSTILE) != 0L)
#define always_peaceful(ptr)	(((ptr)->mflags2 & M2_PEACEFUL) != 0L)
#define race_hostile(ptr)	(((ptr)->mflags2 & urace.hatemask) != 0L)
#define race_peaceful(ptr)	(((ptr)->mflags2 & urace.lovemask) != 0L)
#define extra_nasty(ptr)	(((ptr)->mflags2 & M2_NASTY) != 0L)
#define strongmonst(ptr)	(((ptr)->mflags2 & M2_STRONG) != 0L)
#define can_breathe(ptr)	attacktype(ptr, AT_BREA)
#define cantwield(ptr)		(nohands(ptr) || verysmall(ptr))
#define could_twoweap(ptr)	((ptr)->mattk[1].aatyp == AT_WEAP)
#define cantweararm(ptr)	(breakarm(ptr) || sliparm(ptr))
#define throws_rocks(ptr)	(((ptr)->mflags2 & M2_ROCKTHROW) != 0L)
#define type_is_pname(ptr)	(((ptr)->mflags2 & M2_PNAME) != 0L)
#define is_thief(ptr)		( (ptr)->mattk[0].adtyp == AD_SGLD || (ptr)->mattk[0].adtyp == AD_SITM \
							||(ptr)->mattk[1].adtyp == AD_SGLD || (ptr)->mattk[1].adtyp == AD_SITM \
							||(ptr)->mattk[2].adtyp == AD_SGLD || (ptr)->mattk[2].adtyp == AD_SITM \
							||(ptr)->mattk[3].adtyp == AD_SGLD || (ptr)->mattk[3].adtyp == AD_SITM \
							||(ptr)->mattk[4].adtyp == AD_SGLD || (ptr)->mattk[4].adtyp == AD_SITM \
							||(ptr)->mattk[5].adtyp == AD_SGLD || (ptr)->mattk[5].adtyp == AD_SITM \
							)
#define is_magical(ptr)		( (ptr)->mattk[0].aatyp == AT_MMGC || (ptr)->mattk[0].aatyp == AT_MAGC \
							||(ptr)->mattk[1].aatyp == AT_MMGC || (ptr)->mattk[1].aatyp == AT_MAGC \
							||(ptr)->mattk[2].aatyp == AT_MMGC || (ptr)->mattk[2].aatyp == AT_MAGC \
							||(ptr)->mattk[3].aatyp == AT_MMGC || (ptr)->mattk[3].aatyp == AT_MAGC \
							||(ptr)->mattk[4].aatyp == AT_MMGC || (ptr)->mattk[4].aatyp == AT_MAGC \
							||(ptr)->mattk[5].aatyp == AT_MMGC || (ptr)->mattk[5].aatyp == AT_MAGC \
							)
#define is_lord(ptr)		(((ptr)->mflags2 & M2_LORD) != 0L)
#define is_prince(ptr)		(((ptr)->mflags2 & M2_PRINCE) != 0L)
#define is_ndemon(ptr)		(is_demon(ptr) && \
				 (((ptr)->mflags2 & (M2_LORD|M2_PRINCE)) == 0L))
#define is_dlord(ptr)		(is_demon(ptr) && is_lord(ptr))
#define is_dprince(ptr)		(is_demon(ptr) && is_prince(ptr))
#define is_minion(ptr)		((ptr)->mflags2 & M2_MINION)
#define likes_gold(ptr)		(((ptr)->mflags2 & M2_GREEDY) != 0L)
#define likes_gems(ptr)		(((ptr)->mflags2 & M2_JEWELS) != 0L)
#define likes_objs(ptr)		(((ptr)->mflags2 & M2_COLLECT) != 0L || \
				 is_armed(ptr))
#define likes_magic(ptr)	(((ptr)->mflags2 & M2_MAGIC) != 0L)
#define webmaker(ptr)		((ptr) == &mons[PM_CAVE_SPIDER] || \
				 (ptr) == &mons[PM_GIANT_SPIDER] || (ptr) == &mons[PM_PHASE_SPIDER] || \
				 (ptr) == &mons[PM_SPROW] || (ptr) == &mons[PM_DRIDER])
#define is_unicorn(ptr)		((ptr)->mlet == S_UNICORN && likes_gems(ptr))
#define is_longworm(ptr)	(((ptr) == &mons[PM_BABY_LONG_WORM]) || \
				 ((ptr) == &mons[PM_LONG_WORM]) || \
				 ((ptr) == &mons[PM_LONG_WORM_TAIL]))
#define is_covetous(ptr)	((ptr->mflags3 & M3_COVETOUS))
#define infravision(ptr)	((ptr->mflags3 & M3_INFRAVISION))
#define infravisible(ptr)	((ptr->mflags3 & M3_INFRAVISIBLE))
#define can_betray(ptr)		((ptr->mflags3 & M3_TRAITOR))
#define opaque(ptr)	(((ptr)->mflags3 & M3_OPAQUE))
#define mteleport(ptr)	(((ptr)->mflags3 & M3_TENGTPORT))
#define is_mplayer(ptr)		(((ptr) >= &mons[PM_ARCHEOLOGIST]) && \
				 ((ptr) <= &mons[PM_WIZARD]))
#define is_rider(ptr)		((ptr) == &mons[PM_DEATH] || \
				 (ptr) == &mons[PM_FAMINE] || \
				 (ptr) == &mons[PM_PESTILENCE] || \
				 (ptr) == &mons[PM_LUCIFER] || \
				 (ptr) == &mons[PM_GREAT_CTHULHU] || \
				 (ptr) == &mons[PM_AXUS] || \
				 (ptr) == &mons[PM_NAZGUL] || \
				 (ptr) == &mons[PM_STRANGE_CORPSE] || \
				 (ptr) == &mons[PM_ELDER_PRIEST] || \
				 (ptr) == &mons[PM_PRIEST_OF_AN_UNKNOWN_GOD])
#define is_placeholder(ptr)	((ptr) == &mons[PM_ORC] || \
				 (ptr) == &mons[PM_GIANT] || \
				 (ptr) == &mons[PM_ELF] || \
				 (ptr) == &mons[PM_HUMAN])

/* return TRUE if the monster tends to revive */
#define is_reviver(ptr)		(is_rider(ptr) || (ptr)->mlet == S_TROLL || (ptr)->mlet == S_FUNGUS)

#define is_demihuman(ptr)	((ptr) == &mons[PM_MINOTAUR] || \
				 (ptr) == &mons[PM_MINOTAUR_PRIESTESS] || \
				 (ptr) == &mons[PM_YETI] || \
				 (ptr) == &mons[PM_SASQUATCH] || \
				 (ptr) == &mons[PM_RED_NAGA_HATCHLING] || \
				 (ptr) == &mons[PM_GOLDEN_NAGA_HATCHLING] || \
				 (ptr) == &mons[PM_BLACK_NAGA_HATCHLING] || \
				 (ptr) == &mons[PM_GUARDIAN_NAGA_HATCHLING] || \
				 (ptr) == &mons[PM_RED_NAGA] || \
				 (ptr) == &mons[PM_BLACK_NAGA] || \
				 (ptr) == &mons[PM_GOLDEN_NAGA] || \
				 (ptr) == &mons[PM_GUARDIAN_NAGA] || \
				 (ptr) == &mons[PM_GNOLL] || \
				 (ptr) == &mons[PM_GNOLL_GHOUL] || \
				 (ptr) == &mons[PM_ANUBITE] || \
				 (ptr) == &mons[PM_GNOLL_MATRIARCH] || \
				 (ptr) == &mons[PM_MIND_FLAYER] || \
				 (ptr) == &mons[PM_MASTER_MIND_FLAYER] || \
				 (ptr) == &mons[PM_DEEP_ONE] || \
				 (ptr) == &mons[PM_DEEPER_ONE] || \
				 (ptr) == &mons[PM_DEEPEST_ONE] || \
				 (ptr) == &mons[PM_MEDUSA] || \
				 (ptr) == &mons[PM_MOUNTAIN_CENTAUR] || \
				 (ptr) == &mons[PM_FOREST_CENTAUR] || \
				 (ptr) == &mons[PM_PLAINS_CENTAUR] || \
				 (ptr) == &mons[PM_BAPHOMET] || \
				 (ptr) == &mons[PM_YEENOGHU])

/* this returns the light's range, or 0 if none; if we add more light emitting
   monsters, we'll likely have to add a new light range field to mons[] */
#define emits_light(ptr)	(((ptr)->mlet == S_LIGHT || \
				  (ptr) == &mons[PM_FLAMING_SPHERE] || \
				  (ptr) == &mons[PM_SHOCKING_SPHERE] || \
				  (ptr) == &mons[PM_FALLEN_ANGEL] || \
				  (ptr) == &mons[PM_FIRE_VORTEX]) ? 1 : \
				 ((ptr) == &mons[PM_FIRE_ELEMENTAL]) ? 2 : \
				 ((ptr) == &mons[PM_SOLAR]|| \
				  (ptr) == &mons[PM_LUCIFER]) ? 7 : 0)
/*	[note: the light ranges above were reduced to 1 for performance...] */
#define likes_lava(ptr)		(ptr == &mons[PM_FIRE_ELEMENTAL] || \
				 ptr == &mons[PM_SALAMANDER])
#define pm_invisible(ptr) ((ptr) == &mons[PM_STALKER] || \
			   (ptr) == &mons[PM_BLACK_LIGHT] ||\
			   (ptr) == &mons[PM_PHANTOM_FUNGUS] ||\
			   (ptr) == &mons[PM_CENTER_OF_ALL] ||\
			   (ptr) == &mons[PM_DARKNESS_GIVEN_HUNGER] ||\
			   (ptr) == &mons[PM_ANCIENT_OF_DEATH]\
			   )

/* could probably add more */
#define likes_fire(ptr)		((ptr) == &mons[PM_FIRE_VORTEX] || \
				  (ptr) == &mons[PM_FLAMING_SPHERE] || \
				 likes_lava(ptr))

#define touch_petrifies(ptr)	((ptr) == &mons[PM_COCKATRICE] || \
				 (ptr) == &mons[PM_CHICKATRICE])

#define is_weeping(ptr)		((ptr) == &mons[PM_WEEPING_ANGEL])

#define is_mind_flayer(ptr)	((ptr) == &mons[PM_MIND_FLAYER] || \
				 (ptr) == &mons[PM_MASTER_MIND_FLAYER]|| \
				 (ptr) == &mons[PM_ALHOON]|| \
				 (ptr) == &mons[PM_GREAT_CTHULHU])

#define nonliving(ptr)		(is_keter(ptr) || is_golem(ptr) || \
				 is_undead(ptr) || is_clockwork(ptr) || \
				 (ptr)->mlet == S_VORTEX || \
				 (ptr) == &mons[PM_MANES])

#define likes_swamp(ptr)	((ptr)->mlet == S_PUDDING || \
				 (ptr)->mlet == S_FUNGUS || \
				 (ptr) == &mons[PM_OCHRE_JELLY])
#define stationary(ptr)		((ptr)->mflags3 & M3_STATIONARY)

/* Used for conduct with corpses, tins, and digestion attacks */
/* G_NOCORPSE monsters might still be swallowed as a purple worm */
/* Maybe someday this could be in mflags... */
#define vegan(ptr)		((ptr)->mlet == S_BLOB || \
				 (ptr)->mlet == S_JELLY ||            \
				 (ptr)->mlet == S_FUNGUS ||           \
				 (ptr)->mlet == S_VORTEX ||           \
				 (ptr)->mlet == S_LIGHT ||            \
				 (ptr)->mlet == S_PLANT ||            \
				((ptr)->mlet == S_ELEMENTAL &&        \
				 (ptr) != &mons[PM_STALKER]) ||       \
				((ptr)->mlet == S_GOLEM &&            \
				 (ptr) != &mons[PM_FLESH_GOLEM] &&    \
				 (ptr) != &mons[PM_LEATHER_GOLEM]) || \
				 (ptr) == &mons[PM_WOOD_TROLL] ||     \
				 noncorporeal(ptr))
#define vegetarian(ptr)		(vegan(ptr) || \
				((ptr)->mlet == S_PUDDING &&         \
				 (ptr) != &mons[PM_BLACK_PUDDING] && \
				 (ptr) != &mons[PM_DARKNESS_GIVEN_HUNGER]))

/* For vampires */
#define has_blood(ptr)		(!vegetarian(ptr) && \
				   (ptr)->mlet != S_GOLEM && \
				   (ptr)->mlet != S_KETER && \
				   (!is_undead(ptr) || is_vampire(ptr)))

/* Keep track of ferns, fern sprouts, fern spores, and other plants */

#define is_fern_sprout(ptr)	((ptr) == &mons[PM_DUNGEON_FERN_SPROUT] || \
				 (ptr) == &mons[PM_SWAMP_FERN_SPROUT])

#define is_fern_spore(ptr)	((ptr) == &mons[PM_DUNGEON_FERN_SPORE] || \
				 (ptr) == &mons[PM_SWAMP_FERN_SPORE])

#define is_fern(ptr)		(is_fern_sprout(ptr) || \
				 (ptr) == &mons[PM_DUNGEON_FERN] || \
				 (ptr) == &mons[PM_SWAMP_FERN])

#define is_vegetation(ptr)	((ptr)->mlet == S_PLANT || is_fern(ptr))

#ifdef CONVICT
#define befriend_with_obj(ptr, obj) ((obj)->oclass == FOOD_CLASS && \
				     (is_domestic(ptr) || (is_rat(ptr) && Role_if(PM_CONVICT))))
#else
#define befriend_with_obj(ptr, obj) ((obj)->oclass == FOOD_CLASS && \
				     is_domestic(ptr))
#endif

#endif /* MONDATA_H */

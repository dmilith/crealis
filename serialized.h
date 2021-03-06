#ifndef _SERIALIZED_H
#define _SERIALIZED_H

#include <iostream>
#include <fstream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>
#include <boost/progress.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/filesystem/operations.hpp>

#include "job.h"
#include "config.h"
#include "character.h"
#include "item.h"
#include "coordinates.h"
#include "place.h"
#include "soul.h"
#include "version.h"
#include "world.h"

#ifdef RUBY_LOCAL_INSTALL
//#include "../local/lib/ruby/1.8/x86_64-linux/ruby.h"
#else
//#include "../lib/ruby/1.8/x86_64-linux/ruby.h"
#endif



namespace boost {
namespace serialization {
        template<class Archive>
        void serialize(Archive & ar, Job & job, const unsigned int version) {
            ar & job.job_id;
            ar & job.job_flags;
            ar & job.type;
            ar & job.actors;
        } // namespace serialization        template<class Archive>
        
        template<class Archive>
        void serialize(Archive & ar, Cworld & world, const unsigned int version) {
            ar & world.x_theritory_size;
            ar & world.y_theritory_size;
            ar & world.gravity; //grawitacja
            ar & world.name;
            ar & world.cl_version; //wersja swiata. od tego zaleza ew niekompatybilnosci
        } // namespace serialization        template<class Archive>
        
        template<class Archive>
				void serialize(Archive & ar, Citem & item, const unsigned int version) {
            ar & item.weight;
            ar & item.size_of_item;
        } // namespace serialization
        
        template<class Archive>
        void serialize(Archive & ar, Ccoordinates & pos, const unsigned int version) {
            ar & pos.position;
            ar & pos.parent_positions;
        } // namespace serialization
        
        template<class Archive>
        void serialize(Archive & ar, Csoul & soul, const unsigned int version) {
            ar & soul.mind_strength;
            ar & soul.mana;
            ar & soul.alignment;
            ar & soul.soul_exist; // czy istnieje dusza czy nie
        } // namespace serialization
        
        template<class Archive>
        void serialize(Archive & ar, Ccharacter & ch, const unsigned int version) {
            ar & ch.dead;
            ar & ch.armor;
            ar & ch.combat_ability;
            ar & ch.health;
            ar & ch.intelligence;
            ar & ch.strength;
            ar & ch.dexterity;
            ar & ch.mind_strength;//cechy postaci
            ar & ch.age; // wiek postaci
            ar & ch.luck; //szczescie moze byc -
            ar & ch.soul;
            ar & ch.gold;
            ar & ch.position;
            ar & ch.items;
            ar & ch.private_box;
            ar & ch.race;
        } // namespace serialization
    } // namespace boost
}

#endif


#pragma once
#include "Serpent.hpp"

namespace Serpent {
    struct wrapper {
		static script* instance;
		static void setParent(script* parent) {
			instance = parent;
		}
		static bool MenuLayer_init(MenuLayer* self);
		static void MenuLayer_onMoreGames(MenuLayer* self, cocos2d::CCObject* p0);
        static void MenuLayer_endGame(MenuLayer* self);
        static void MenuLayer_firstNetworkTest(MenuLayer* self);
        static void MenuLayer_onAchievements(MenuLayer* self, cocos2d::CCObject* sender);
        static void MenuLayer_onCreator(MenuLayer* self, cocos2d::CCObject* sender);
        static void MenuLayer_onDaily(MenuLayer* self, cocos2d::CCObject* sender);
        static void MenuLayer_onGarage(MenuLayer* self, cocos2d::CCObject* sender);
        static void MenuLayer_onMyProfile(MenuLayer* self, cocos2d::CCObject* sender);
        static void MenuLayer_onOptions(MenuLayer* self, cocos2d::CCObject* sender);
        static void MenuLayer_onOptionsInstant(MenuLayer* self);
        static void MenuLayer_onPlay(MenuLayer* self, cocos2d::CCObject* sender);
        static void MenuLayer_onQuit(MenuLayer* self, cocos2d::CCObject* sender);
        static void MenuLayer_onRobTop(MenuLayer* self, cocos2d::CCObject* sender);
        static void MenuLayer_onStats(MenuLayer* self, cocos2d::CCObject* sender);
        static void MenuLayer_openOptions(MenuLayer* self, bool videoOptions);
        static void MenuLayer_showTOS(MenuLayer* self);
        static void MenuLayer_updateUserProfileButton(MenuLayer* self);
        static void MenuLayer_willClose(MenuLayer* self);
	};
}
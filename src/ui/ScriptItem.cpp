#include "ScriptItem.hpp"
#include <Geode/Geode.hpp>

using namespace Serpent::ui;
using namespace geode::prelude;


// used `ModItem` to know what im doing while coding this node
bool ScriptItem::init(matjson::Value json, std::function<void(CCObject*)> onButton) {
    if (!CCNode::init()) return false;
    this->setID(fmt::format("script-item/{}", json["id"].as_string()));
    

    auto bg = CCScale9Sprite::create("GJ_square01.png");
    bg->setID("background");
    //bg->setOpacity(55);
    bg->ignoreAnchorPointForPosition(false);
    bg->setAnchorPoint({0.5f, 0.5f});
    bg->setScale(0.7f);
    this->setContentSize({200, 30});
    bg->setContentSize((m_obContentSize - ccp(6, 0)) / bg->getScale());
    bg->setPosition(m_obContentSize / 2);

    mainContainer = CCNode::create();
    mainContainer->setID("main-container");
    mainContainer->setScale(0.4f);
    mainContainer->setAnchorPoint({0.0f, 0.4f});
    mainContainer->setLayout(
        ColumnLayout::create()
            //->setAxisReverse(true)
            ->setAxisAlignment(AxisAlignment::Even)
            ->setCrossAxisLineAlignment(AxisAlignment::Start)
            ->setGap(0)
    );
    mainContainer->getLayout()->ignoreInvisibleChildren(true);


    title = CCNode::create();
    title->setID("title-container");
    title->setAnchorPoint({0.5f, 1.0f});
    title->setLayout(
        RowLayout::create()
            //->setDefaultScaleLimits(0.1f, 1.0f)
            ->setAxisAlignment(AxisAlignment::Start)
    );

    devContainer = CCMenu::create();
    devContainer->setID("developer-container");
    devContainer->ignoreAnchorPointForPosition(false);
    devContainer->setAnchorPoint({0.0f, 0.0f});

    dev = CCLabelBMFont::create(json["developer"].as_string().c_str(), "goldFont.fnt");

    devContainer->addChild(dev);

    devContainer->setLayout(
        RowLayout::create()
            ->setAxisAlignment(AxisAlignment::Start)
    );

    mainContainer->addChild(devContainer);

    CCSize titleSpace {
        m_obContentSize.width / 2 - m_obContentSize.height,
        m_obContentSize.height + 10 - 5
    };

    mainContainer->addChild(title);

    titleLabel = CCLabelBMFont::create(json["name"].as_string().c_str(), "bigFont.fnt");
    titleLabel->setID("title-label");
    titleLabel->setLayoutOptions(AxisLayoutOptions::create()->setScalePriority(1));
    title->addChild(titleLabel);

    title->setContentWidth((titleSpace.width) / mainContainer->getScale());

    devContainer->setContentWidth({titleSpace.width / mainContainer->getScale()});

    mainContainer->setPosition(10, m_obContentSize.height / 2);
    mainContainer->setContentSize(ccp(titleSpace.width, titleSpace.height) / mainContainer->getScale());

    
    viewMenu = CCMenu::create();
    viewMenu->setID("view-menu");
    viewMenu->setAnchorPoint({1.0f, 0.5f});
    viewMenu->setScale(0.4f);
    auto sprite = ButtonSprite::create("View", "bigFont.fnt", "geode.loader/GE_button_05.png");
    

    auto viewBtn = CCMenuItemExt::createSpriteExtra(sprite, onButton);
    viewMenu->addChild(viewBtn);

    viewMenu->setLayout(
        RowLayout::create()
            ->setAxisReverse(true)
            ->setAxisAlignment(AxisAlignment::End)
            ->setGap(10)
    );
    

    this->addChild(bg);
    this->addChild(mainContainer);
    this->addChildAtPosition(viewMenu, Anchor::Right, ccp(-10, 0));
    mainContainer->updateLayout();
    title->updateLayout();
    devContainer->updateLayout();
    viewMenu->updateLayout();
    this->updateLayout();
    return true;
}

ScriptItem* ScriptItem::create(matjson::Value json, std::function<void(CCObject*)> onButton) {
    auto ret = new ScriptItem();
    if (ret->init(json, onButton)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}
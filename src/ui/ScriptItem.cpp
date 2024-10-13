#include "ScriptItem.hpp"
#include <Geode/Geode.hpp>

using namespace Serpent::ui;
using namespace geode::prelude;

bool ScriptItem::init(matjson::Value json) {
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
            ->setDefaultScaleLimits(0.1f, 1.0f)
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

    version = CCLabelBMFont::create(json["version"].as_string().c_str(), "bigFont.fnt");
    version->setID("version-label");
    version->setColor({ 0, 255, 255 });
    version->setLayoutOptions(AxisLayoutOptions::create()->setScaleLimits(std::nullopt, 0.7f));

    title->addChild(version);



    title->setContentWidth((titleSpace.width) / mainContainer->getScale());

    devContainer->setContentWidth({titleSpace.width / mainContainer->getScale()});

    mainContainer->setPosition(10, m_obContentSize.height / 2);
    mainContainer->setContentSize(ccp(titleSpace.width, titleSpace.height) / mainContainer->getScale());

    
    this->addChild(bg);
    this->addChild(mainContainer);
    mainContainer->updateLayout();
    title->updateLayout();
    version->updateLayout();
    devContainer->updateLayout();
    this->updateLayout();
    return true;
}

ScriptItem* ScriptItem::create(matjson::Value json) {
    auto ret = new ScriptItem();
    if (ret->init(json)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}
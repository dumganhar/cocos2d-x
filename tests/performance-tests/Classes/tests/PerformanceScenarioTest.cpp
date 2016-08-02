#include "PerformanceScenarioTest.h"
#include "Profile.h"
#include "cocos/audio/include/AudioEngine.h"

using namespace cocos2d::experimental;
USING_NS_CC;

#define DELAY_TIME              4
#define STAT_TIME               3

PerformceScenarioTests::PerformceScenarioTests()
{
    Director::getInstance()->getTextureCache()->removeUnusedTextures();
    SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
    AudioEngine::uncacheAll();
    
    ADD_TEST_CASE(ScenarioTest);
}

////////////////////////////////////////////////////////
//
// ScenarioTest
//
////////////////////////////////////////////////////////
int ScenarioTest::_initParticleNum = 500;
int ScenarioTest::_parStepNum = 500;
int ScenarioTest::_initSpriteNum = 500;
int ScenarioTest::_spriteStepNum = 500;
int ScenarioTest::_initParsysNum = 5;
int ScenarioTest::_parsysStepNum = 5;

typedef struct
{
    int spriteCount;
    int particleCount;
    int particleSystemCount;
} TestCaseInfo;

static TestCaseInfo autoTestCounts[] = {
    { 500, 500, 50 },
    { 1000, 1000, 100 },
    { 1500, 1500, 150 }
};

static const char* __imagesToPreload[] = {
    "Images/PlanetCute-1024x1024.png",
    "Images/b1.png",
    "Images/b2.png",
    "Images/close.png",
    "Images/f1.png",
    "Images/f2.png",
    "Images/fire.png",
    "Images/grossini.png",
    "Images/grossini_dance_01.png",
    "Images/grossini_dance_02.png",
    "Images/grossini_dance_03.png",
    "Images/grossini_dance_04.png",
    "Images/grossini_dance_05.png",
    "Images/grossini_dance_06.png",
    "Images/grossini_dance_07.png",
    "Images/grossini_dance_08.png",
    "Images/grossini_dance_09.png",
    "Images/grossini_dance_10.png",
    "Images/grossini_dance_11.png",
    "Images/grossini_dance_12.png",
    "Images/grossini_dance_13.png",
    "Images/grossini_dance_14.png",
    "Images/grossini_dance_atlas.png",
    "Images/grossini_polygon.png",
    "Images/grossini_quad.png",
    "Images/grossinis_sister1.png",
    "Images/grossinis_sister1_sp.png",
    "Images/grossinis_sister2.png",
    "Images/grossinis_sister2_sp.png",
    "Images/landscape-1024x1024.png",
    "Images/r1.png",
    "Images/r2.png",
    "Images/spritesheet1.png",
    "Images/test_image.png",
    "Images/texture1024x1024.png",
    "Images/texture512x512.png",
    "sprites/achievement1.png",
    "sprites/achievement10.png",
    "sprites/achievement11.png",
    "sprites/achievement12.png",
    "sprites/achievement13.png",
    "sprites/achievement14.png",
    "sprites/achievement15.png",
    "sprites/achievement16.png",
    "sprites/achievement17.png",
    "sprites/achievement18.png",
    "sprites/achievement19.png",
    "sprites/achievement2.png",
    "sprites/achievement3.png",
    "sprites/achievement4.png",
    "sprites/achievement5.png",
    "sprites/achievement6.png",
    "sprites/achievement7.png",
    "sprites/achievement8.png",
    "sprites/achievement9.png",
    "sprites/armory.png",
    "sprites/aura.png",
    "sprites/avatarAmber.png",
    "sprites/avatarArnold.png",
    "sprites/avatarDrakhelis.png",
    "sprites/avatarHan.png",
    "sprites/avatarJacqueline.png",
    "sprites/avatarKing.png",
    "sprites/avatarMambo.png",
    "sprites/avatarPreview1.png",
    "sprites/avatarPreview10.png",
    "sprites/avatarPreview11.png",
    "sprites/avatarPreview12.png",
    "sprites/avatarPreview13.png",
    "sprites/avatarPreview2.png",
    "sprites/avatarPreview3.png",
    "sprites/avatarPreview4.png",
    "sprites/avatarPreview5.png",
    "sprites/avatarPreview6.png",
    "sprites/avatarPreview7.png",
    "sprites/avatarPreview8.png",
    "sprites/avatarPreview9.png",
    "sprites/avatarRous.png",
    "sprites/avatarSambinho.png",
    "sprites/avatarSammy.png",
    "sprites/avatarVincent.png",
    "sprites/avatarWukong.png",
    "sprites/bg.png",
    "sprites/cardLayout.png",
    "sprites/cardLayoutHand.png",
    "sprites/clouds.png",
    "sprites/confeti.png",
    "sprites/containerBox.png",
    "sprites/dailyReward.png",
    "sprites/entity.png",
    "sprites/facebookDefaultPhoto.png",
    "sprites/form.png",
    "sprites/gadget01.png",
    "sprites/gadget02.png",
    "sprites/gui.png",
    "sprites/levelChaos01.png",
    "sprites/levelChaos02-1.png",
    "sprites/levelChaos02-2.png",
    "sprites/levelChaos03.png",
    "sprites/levelChina01.png",
    "sprites/levelChina02-1.png",
    "sprites/levelChina02-2.png",
    "sprites/levelChina03.png",
    "sprites/levelEgypt01.png",
    "sprites/levelEgypt02.png",
    "sprites/levelEgypt03.png",
    "sprites/levelEntry01.png",
    "sprites/levelEntry02.png",
    "sprites/levelEntry03.png",
    "sprites/levelJapan01.png",
    "sprites/levelJapan02-1.png",
    "sprites/levelJapan02-2.png",
    "sprites/levelJapan03.png",
    "sprites/levelJungle01.png",
    "sprites/levelJungle02-1.png",
    "sprites/levelJungle02-2.png",
    "sprites/levelJungle02-3.png",
    "sprites/levelJungle03.png",
    "sprites/levelPreview.png",
    "sprites/levelSnow01.png",
    "sprites/levelSnow02-1.png",
    "sprites/levelSnow02-2.png",
    "sprites/levelSnow02-3.png",
    "sprites/levelSnow03.png",
    "sprites/levelSunset01.png",
    "sprites/levelSunset02-1.png",
    "sprites/levelSunset02-2.png",
    "sprites/levelSunset02-3.png",
    "sprites/levelSunset03.png",
    "sprites/levelTempest01.png",
    "sprites/levelTempest02.png",
    "sprites/levelTransition.png",
    "sprites/levelVolcano01.png",
    "sprites/levelVolcano02-1.png",
    "sprites/levelVolcano02-2.png",
    "sprites/levelVolcano03.png",
    "sprites/lightning.png",
    "sprites/menu.png",
    "sprites/mission1.png",
    "sprites/mission10.png",
    "sprites/mission11.png",
    "sprites/mission12.png",
    "sprites/mission13.png",
    "sprites/mission14.png",
    "sprites/mission15.png",
    "sprites/mission16.png",
    "sprites/mission17.png",
    "sprites/mission18.png",
    "sprites/mission19.png",
    "sprites/mission2.png",
    "sprites/mission20.png",
    "sprites/mission21.png",
    "sprites/mission22.png",
    "sprites/mission23.png",
    "sprites/mission24.png",
    "sprites/mission25.png",
    "sprites/mission26.png",
    "sprites/mission27.png",
    "sprites/mission28.png",
    "sprites/mission29.png",
    "sprites/mission3.png",
    "sprites/mission30.png",
    "sprites/mission31.png",
    "sprites/mission32.png",
    "sprites/mission33.png",
    "sprites/mission34.png",
    "sprites/mission35.png",
    "sprites/mission36.png",
    "sprites/mission37.png",
    "sprites/mission38.png",
    "sprites/mission39.png",
    "sprites/mission4.png",
    "sprites/mission40.png",
    "sprites/mission41.png",
    "sprites/mission42.png",
    "sprites/mission43.png",
    "sprites/mission44.png",
    "sprites/mission45.png",
    "sprites/mission46.png",
    "sprites/mission47.png",
    "sprites/mission48.png",
    "sprites/mission49.png",
    "sprites/mission5.png",
    "sprites/mission50.png",
    "sprites/mission51.png",
    "sprites/mission52.png",
    "sprites/mission53.png",
    "sprites/mission54.png",
    "sprites/mission55.png",
    "sprites/mission56.png",
    "sprites/mission57.png",
    "sprites/mission58.png",
    "sprites/mission59.png",
    "sprites/mission6.png",
    "sprites/mission60.png",
    "sprites/mission61.png",
    "sprites/mission62.png",
    "sprites/mission63.png",
    "sprites/mission64.png",
    "sprites/mission65.png",
    "sprites/mission66.png",
    "sprites/mission7.png",
    "sprites/mission8.png",
    "sprites/mission9.png",
    "sprites/nextScore.png",
    "sprites/range1.png",
    "sprites/range10.png",
    "sprites/range11.png",
    "sprites/range12.png",
    "sprites/range13.png",
    "sprites/range14.png",
    "sprites/range15.png",
    "sprites/range16.png",
    "sprites/range17.png",
    "sprites/range18.png",
    "sprites/range19.png",
    "sprites/range2.png",
    "sprites/range20.png",
    "sprites/range21.png",
    "sprites/range22.png",
    "sprites/range23.png",
    "sprites/range24.png",
    "sprites/range25.png",
    "sprites/range3.png",
    "sprites/range4.png",
    "sprites/range5.png",
    "sprites/range6.png",
    "sprites/range7.png",
    "sprites/range8.png",
    "sprites/range9.png",
    "sprites/rangeMini.png",
    "sprites/refraction.png",
    "sprites/review.png",
    "sprites/sfx.png",
    "sprites/shop.png",
    "sprites/shopCoins.png",
    "sprites/spinner.png",
    "sprites/stats.png",
    "sprites/tutorial.png",
    "sprites/uniform.png",
    "sprites/vehicleBike.png",
    "sprites/vehicleBoat.png",
    "sprites/vehicleCarBlack.png",
    "sprites/vehicleCarRed.png",
    "sprites/vehicleCarWhite.png",
    "sprites/vehicleCarriage.png",
    "sprites/vehicleCloud.png",
    "sprites/vehicleDragon.png",
    "sprites/vehicleHippo.png",
    "sprites/vehiclePirate.png",
    "sprites/vehiclePirateKraken.png",
    "sprites/vehiclePolice.png",
    "sprites/vehiclePreview01.png",
    "sprites/vehiclePreview02.png",
    "sprites/vehiclePreview03.png",
    "sprites/vehicleShark.png",
    "sprites/vehicleSubmarine.png",
    "sprites/vehicleSurf.png",
    "sprites/vehicleYacht.png",
};

static const char* __plistToPreload[] = {
    "sprites/achievement1.plist",
    "sprites/achievement10.plist",
    "sprites/achievement11.plist",
    "sprites/achievement12.plist",
    "sprites/achievement13.plist",
    "sprites/achievement14.plist",
    "sprites/achievement15.plist",
    "sprites/achievement16.plist",
    "sprites/achievement17.plist",
    "sprites/achievement18.plist",
    "sprites/achievement19.plist",
    "sprites/achievement2.plist",
    "sprites/achievement3.plist",
    "sprites/achievement4.plist",
    "sprites/achievement5.plist",
    "sprites/achievement6.plist",
    "sprites/achievement7.plist",
    "sprites/achievement8.plist",
    "sprites/achievement9.plist",
    "sprites/armory.plist",
    "sprites/aura.plist",
    "sprites/avatarAmber.plist",
    "sprites/avatarArnold.plist",
    "sprites/avatarDrakhelis.plist",
    "sprites/avatarHan.plist",
    "sprites/avatarJacqueline.plist",
    "sprites/avatarKing.plist",
    "sprites/avatarMambo.plist",
    "sprites/avatarPreview1.plist",
    "sprites/avatarPreview10.plist",
    "sprites/avatarPreview11.plist",
    "sprites/avatarPreview12.plist",
    "sprites/avatarPreview13.plist",
    "sprites/avatarPreview2.plist",
    "sprites/avatarPreview3.plist",
    "sprites/avatarPreview4.plist",
    "sprites/avatarPreview5.plist",
    "sprites/avatarPreview6.plist",
    "sprites/avatarPreview7.plist",
    "sprites/avatarPreview8.plist",
    "sprites/avatarPreview9.plist",
    "sprites/avatarRous.plist",
    "sprites/avatarSambinho.plist",
    "sprites/avatarSammy.plist",
    "sprites/avatarVincent.plist",
    "sprites/avatarWukong.plist",
    "sprites/cardLayout.plist",
    "sprites/cardLayoutBackground.plist",
    "sprites/cardLayoutHand.plist",
    "sprites/clouds.plist",
    "sprites/containerBox.plist",
    "sprites/dailyReward.plist",
    "sprites/entity.plist",
    "sprites/form.plist",
    "sprites/gadget01.plist",
    "sprites/gadget02.plist",
    "sprites/gui.plist",
    "sprites/levelChaos01.plist",
    "sprites/levelChaos02-1.plist",
    "sprites/levelChaos02-2.plist",
    "sprites/levelChaos03.plist",
    "sprites/levelChina01.plist",
    "sprites/levelChina02-1.plist",
    "sprites/levelChina02-2.plist",
    "sprites/levelChina03.plist",
    "sprites/levelEgypt01.plist",
    "sprites/levelEgypt02.plist",
    "sprites/levelEgypt03.plist",
    "sprites/levelEntry01.plist",
    "sprites/levelEntry02.plist",
    "sprites/levelEntry03.plist",
    "sprites/levelJapan01.plist",
    "sprites/levelJapan02-1.plist",
    "sprites/levelJapan02-2.plist",
    "sprites/levelJapan03.plist",
    "sprites/levelJungle01.plist",
    "sprites/levelJungle02-1.plist",
    "sprites/levelJungle02-2.plist",
    "sprites/levelJungle02-3.plist",
    "sprites/levelJungle03.plist",
    "sprites/levelPreview.plist",
    "sprites/levelSnow01.plist",
    "sprites/levelSnow02-1.plist",
    "sprites/levelSnow02-2.plist",
    "sprites/levelSnow02-3.plist",
    "sprites/levelSnow03.plist",
    "sprites/levelSunset01.plist",
    "sprites/levelSunset02-1.plist",
    "sprites/levelSunset02-2.plist",
    "sprites/levelSunset02-3.plist",
    "sprites/levelSunset03.plist",
    "sprites/levelTempest01.plist",
    "sprites/levelTempest02.plist",
    "sprites/levelTransition.plist",
    "sprites/levelVolcano01.plist",
    "sprites/levelVolcano02-1.plist",
    "sprites/levelVolcano02-2.plist",
    "sprites/levelVolcano03.plist",
    "sprites/loading.plist",
    "sprites/menu.plist",
    "sprites/mission1.plist",
    "sprites/mission10.plist",
    "sprites/mission11.plist",
    "sprites/mission12.plist",
    "sprites/mission13.plist",
    "sprites/mission14.plist",
    "sprites/mission15.plist",
    "sprites/mission16.plist",
    "sprites/mission17.plist",
    "sprites/mission18.plist",
    "sprites/mission19.plist",
    "sprites/mission2.plist",
    "sprites/mission20.plist",
    "sprites/mission21.plist",
    "sprites/mission22.plist",
    "sprites/mission23.plist",
    "sprites/mission24.plist",
    "sprites/mission25.plist",
    "sprites/mission26.plist",
    "sprites/mission27.plist",
    "sprites/mission28.plist",
    "sprites/mission29.plist",
    "sprites/mission3.plist",
    "sprites/mission30.plist",
    "sprites/mission31.plist",
    "sprites/mission32.plist",
    "sprites/mission33.plist",
    "sprites/mission34.plist",
    "sprites/mission35.plist",
    "sprites/mission36.plist",
    "sprites/mission37.plist",
    "sprites/mission38.plist",
    "sprites/mission39.plist",
    "sprites/mission4.plist",
    "sprites/mission40.plist",
    "sprites/mission41.plist",
    "sprites/mission42.plist",
    "sprites/mission43.plist",
    "sprites/mission44.plist",
    "sprites/mission45.plist",
    "sprites/mission46.plist",
    "sprites/mission47.plist",
    "sprites/mission48.plist",
    "sprites/mission49.plist",
    "sprites/mission5.plist",
    "sprites/mission50.plist",
    "sprites/mission51.plist",
    "sprites/mission52.plist",
    "sprites/mission53.plist",
    "sprites/mission54.plist",
    "sprites/mission55.plist",
    "sprites/mission56.plist",
    "sprites/mission57.plist",
    "sprites/mission58.plist",
    "sprites/mission59.plist",
    "sprites/mission6.plist",
    "sprites/mission60.plist",
    "sprites/mission61.plist",
    "sprites/mission62.plist",
    "sprites/mission63.plist",
    "sprites/mission64.plist",
    "sprites/mission65.plist",
    "sprites/mission66.plist",
    "sprites/mission7.plist",
    "sprites/mission8.plist",
    "sprites/mission9.plist",
    "sprites/nextScore.plist",
    "sprites/range1.plist",
    "sprites/range10.plist",
    "sprites/range11.plist",
    "sprites/range12.plist",
    "sprites/range13.plist",
    "sprites/range14.plist",
    "sprites/range15.plist",
    "sprites/range16.plist",
    "sprites/range17.plist",
    "sprites/range18.plist",
    "sprites/range19.plist",
    "sprites/range2.plist",
    "sprites/range20.plist",
    "sprites/range21.plist",
    "sprites/range22.plist",
    "sprites/range23.plist",
    "sprites/range24.plist",
    "sprites/range25.plist",
    "sprites/range3.plist",
    "sprites/range4.plist",
    "sprites/range5.plist",
    "sprites/range6.plist",
    "sprites/range7.plist",
    "sprites/range8.plist",
    "sprites/range9.plist",
    "sprites/rangeMini.plist",
    "sprites/refraction.plist",
    "sprites/review.plist",
    "sprites/sfx.plist",
    "sprites/shop.plist",
    "sprites/shopCoins.plist",
    "sprites/stats.plist",
    "sprites/tutorial.plist",
    "sprites/uniform.plist",
    "sprites/vehicleBike.plist",
    "sprites/vehicleBoat.plist",
    "sprites/vehicleCarBlack.plist",
    "sprites/vehicleCarRed.plist",
    "sprites/vehicleCarWhite.plist",
    "sprites/vehicleCarriage.plist",
    "sprites/vehicleCloud.plist",
    "sprites/vehicleDragon.plist",
    "sprites/vehicleHippo.plist",
    "sprites/vehiclePirate.plist",
    "sprites/vehiclePirateKraken.plist",
    "sprites/vehiclePolice.plist",
    "sprites/vehiclePreview01.plist",
    "sprites/vehiclePreview02.plist",
    "sprites/vehiclePreview03.plist",
    "sprites/vehicleShark.plist",
    "sprites/vehicleSubmarine.plist",
    "sprites/vehicleSurf.plist",
    "sprites/vehicleYacht.plist",
};

static const char* __soundToPreload[] = {
    "sounds/advanceFinish.ogg",
    "sounds/advanceLoop.ogg",
    "sounds/ball01.ogg",
    "sounds/ball02.ogg",
    "sounds/ball03.ogg",
    "sounds/ballHit01.ogg",
    "sounds/ballHit02.ogg",
    "sounds/bigRocket01.ogg",
    "sounds/bigRocket02.ogg",
    "sounds/bigRocket03.ogg",
    "sounds/bling.ogg",
    "sounds/boatDive.ogg",
    "sounds/boatJump.ogg",
    "sounds/boatSplash.ogg",
    "sounds/bonus.ogg",
    "sounds/boxExplosion.ogg",
    "sounds/bulletTime.ogg",
    "sounds/bulletTimeReverse.ogg",
    "sounds/buttonBuy.ogg",
    "sounds/buttonClose.ogg",
    "sounds/buttonOpen.ogg",
    "sounds/cannonBall01.ogg",
    "sounds/cannonBall02.ogg",
    "sounds/cannonBall03.ogg",
    "sounds/cardHold.ogg",
    "sounds/cardUnhold.ogg",
    "sounds/caveDrop01.ogg",
    "sounds/caveDrop02.ogg",
    "sounds/caveDrop03.ogg",
    "sounds/caveDrop04.ogg",
    "sounds/cloudLoop.ogg",
    "sounds/cluster01.ogg",
    "sounds/cluster02.ogg",
    "sounds/cluster03.ogg",
    "sounds/clusterGrape01.ogg",
    "sounds/clusterGrape02.ogg",
    "sounds/clusterGrape03.ogg",
    "sounds/coinPickUp01.ogg",
    "sounds/coinPickUp02.ogg",
    "sounds/coinPickUp03.ogg",
    "sounds/confetti01.ogg",
    "sounds/confetti02.ogg",
    "sounds/doorClose.ogg",
    "sounds/doorOpen.ogg",
    "sounds/doubleJump.ogg",
    "sounds/enemyHeavyMachineGun01.ogg",
    "sounds/enemyHeavyMachineGun02.ogg",
    "sounds/enemyHeavyMachineGun03.ogg",
    "sounds/enemyPistol.ogg",
    "sounds/enemyTouched.ogg",
    "sounds/explosion01.ogg",
    "sounds/explosion02.ogg",
    "sounds/explosion03.ogg",
    "sounds/fireworksExplosion01.ogg",
    "sounds/fireworksExplosion02.ogg",
    "sounds/fireworksWhistle01.ogg",
    "sounds/fireworksWhistle02.ogg",
    "sounds/fish.ogg",
    "sounds/flameShot01.ogg",
    "sounds/flameShot02.ogg",
    "sounds/flameShot03.ogg",
    "sounds/flameShotHit01.ogg",
    "sounds/flameShotHit02.ogg",
    "sounds/flameShotHit03.ogg",
    "sounds/flipCard01.ogg",
    "sounds/flipCard02.ogg",
    "sounds/flipCard03.ogg",
    "sounds/guiCoin01.ogg",
    "sounds/guiCoin02.ogg",
    "sounds/heavyMachineGun01.ogg",
    "sounds/heavyMachineGun02.ogg",
    "sounds/heavyMachineGun03.ogg",
    "sounds/helicopterLoop.ogg",
    "sounds/hippo01.ogg",
    "sounds/hippo02.ogg",
    "sounds/hippo03.ogg",
    "sounds/homingMissile01.ogg",
    "sounds/homingMissile02.ogg",
    "sounds/homingMissile03.ogg",
    "sounds/krakenScream.ogg",
    "sounds/lamp01.ogg",
    "sounds/lamp02.ogg",
    "sounds/lamp03.ogg",
    "sounds/laser01.ogg",
    "sounds/laser02.ogg",
    "sounds/laser03.ogg",
    "sounds/laserHit01.ogg",
    "sounds/laserHit02.ogg",
    "sounds/laserHit03.ogg",
    "sounds/levelUp.ogg",
    "sounds/menu.ogg",
    "sounds/missileWhistle01.ogg",
    "sounds/missileWhistle02.ogg",
    "sounds/musicLevel.ogg",
    "sounds/musicMenu.ogg",
    "sounds/musicSamba.ogg",
    "sounds/musicShop.ogg",
    "sounds/navigation.ogg",
    "sounds/overcharge.ogg",
    "sounds/pistol01.ogg",
    "sounds/pistol02.ogg",
    "sounds/pistol03.ogg",
    "sounds/pistolHitFlesh01.ogg",
    "sounds/pistolHitFlesh02.ogg",
    "sounds/pistolHitFlesh03.ogg",
    "sounds/pistolHitMetal01.ogg",
    "sounds/pistolHitMetal02.ogg",
    "sounds/pistolHitMetal03.ogg",
    "sounds/pistolHitWood01.ogg",
    "sounds/pistolHitWood02.ogg",
    "sounds/pistolHitWood03.ogg",
    "sounds/pistolOvercharge.ogg",
    "sounds/planeLoop.ogg",
    "sounds/plasma01.ogg",
    "sounds/plasma02.ogg",
    "sounds/plasma03.ogg",
    "sounds/plasmaHit01.ogg",
    "sounds/plasmaHit02.ogg",
    "sounds/plasmaHit03.ogg",
    "sounds/plasmaLightning01.ogg",
    "sounds/plasmaLightning02.ogg",
    "sounds/plasmaLightning03.ogg",
    "sounds/pokerChip.ogg",
    "sounds/powerUpAdvance.ogg",
    "sounds/powerUpAssembly.ogg",
    "sounds/powerUpCannon.ogg",
    "sounds/powerUpCluster.ogg",
    "sounds/powerUpFlameThrower.ogg",
    "sounds/powerUpFootball.ogg",
    "sounds/powerUpHealthPack.ogg",
    "sounds/powerUpHeavyMachineGun.ogg",
    "sounds/powerUpHomingMissile.ogg",
    "sounds/powerUpLaserGun.ogg",
    "sounds/powerUpPlasma.ogg",
    "sounds/powerUpRedLaser.ogg",
    "sounds/powerUpRocketLauncher.ogg",
    "sounds/powerUpSamba.ogg",
    "sounds/powerUpSpreadGun.ogg",
    "sounds/rain.ogg",
    "sounds/releaseTheKraken.ogg",
    "sounds/rocketLauncher01.ogg",
    "sounds/rocketLauncher02.ogg",
    "sounds/rocketLauncher03.ogg",
    "sounds/rocketLauncherHit01.ogg",
    "sounds/rocketLauncherHit02.ogg",
    "sounds/rocketLauncherHit03.ogg",
    "sounds/scream01.ogg",
    "sounds/scream02.ogg",
    "sounds/scream03.ogg",
    "sounds/scream04.ogg",
    "sounds/scream05.ogg",
    "sounds/screamAmber.ogg",
    "sounds/screamArnold.ogg",
    "sounds/screamHan.ogg",
    "sounds/screamJacqueline.ogg",
    "sounds/screamMambo.ogg",
    "sounds/screamRous.ogg",
    "sounds/screamSambinho.ogg",
    "sounds/screamVincent.ogg",
    "sounds/scrollClick.ogg",
    "sounds/selectAmber01.ogg",
    "sounds/selectAmber02.ogg",
    "sounds/selectArnold01.ogg",
    "sounds/selectArnold02.ogg",
    "sounds/selectDrakhelis01.ogg",
    "sounds/selectDrakhelis02.ogg",
    "sounds/selectHan01.ogg",
    "sounds/selectHan02.ogg",
    "sounds/selectJacqueline01.ogg",
    "sounds/selectJacqueline02.ogg",
    "sounds/selectKing01.ogg",
    "sounds/selectKing02.ogg",
    "sounds/selectMambo01.ogg",
    "sounds/selectMambo02.ogg",
    "sounds/selectRose01.ogg",
    "sounds/selectRose02.ogg",
    "sounds/selectSambinho01.ogg",
    "sounds/selectSambinho02.ogg",
    "sounds/selectSammy01.ogg",
    "sounds/selectSammy02.ogg",
    "sounds/selectVincent01.ogg",
    "sounds/selectVincent02.ogg",
    "sounds/selectWukong01.ogg",
    "sounds/selectWukong02.ogg",
    "sounds/sharkBite.ogg",
    "sounds/sharkClap.ogg",
    "sounds/shieldBroken.ogg",
    "sounds/shotgun01.ogg",
    "sounds/shotgun02.ogg",
    "sounds/shotgun03.ogg",
    "sounds/siren.ogg",
    "sounds/slam.ogg",
    "sounds/submarineDoors.ogg",
    "sounds/submarineIn.ogg",
    "sounds/submarineOut.ogg",
    "sounds/thunder01.ogg",
    "sounds/thunder02.ogg",
    "sounds/ticTac.ogg",
    "sounds/waterCoinDrop01.ogg",
    "sounds/waterCoinDrop02.ogg",
    "sounds/waterDrop01.ogg",
    "sounds/waterDrop02.ogg",
    "sounds/waterSplashBig01.ogg",
    "sounds/waterSplashBig02.ogg",
    "sounds/waterSplashBig03.ogg",
    "sounds/waterSplashSmall01.ogg",
    "sounds/waterSplashSmall02.ogg",
    "sounds/waterSplashSmall03.ogg",
    "sounds/whisper01.ogg",
    "sounds/whisper02.ogg",
    "sounds/whisper03.ogg",
    "sounds/wings.ogg",
    "sounds/woosh.ogg",
};

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

ScenarioTest::~ScenarioTest()
{
    *_isDestroyed = true;
}

bool ScenarioTest::init()
{
    _loadingPercent = 0;
    _isDestroyed = std::make_shared<bool>(false);
    
    if (TestCase::init())
    {
//        performTests();
        
        _loadingLabel = Label::createWithTTF("Loading 00%", "fonts/arial.ttf", 64);
        _loadingLabel->setPosition(VisibleRect::center());
        addChild(_loadingLabel);
        

        // Picture
        int picCount = ARRAY_SIZE(__imagesToPreload);
        int soundCount = 0;//ARRAY_SIZE(__soundToPreload);
        
        int taskCount = picCount + soundCount;
        std::shared_ptr<int> taskIndex = std::make_shared<int>(0);
        
        auto setLoadingLabel = [=](){
            char s[100] = {0};
            _loadingPercent = (int) (*taskIndex * 100.0f / taskCount);
            if (*taskIndex == taskCount-1)
            {
                _loadingPercent = 100;
            }
            
            snprintf(s, sizeof(s), "Loading %02d%%", _loadingPercent);
            _loadingLabel->setString(s);
            
            if (_loadingPercent >= 100)
            {
                _loadingLabel->removeFromParent();
                performTests();
            }
        };
        
        for (int i = 0; i < picCount; ++i)
        {
            std::shared_ptr<bool> isDestroyed = _isDestroyed;
            Director::getInstance()->getTextureCache()->addImageAsync(__imagesToPreload[i], [=](Texture2D* texture){
                if (*isDestroyed)
                {
                    return;
                }
                
                int plistIndex = std::min<int>(i, (ARRAY_SIZE(__plistToPreload)-1));
                FileUtils::getInstance()->getStringFromFile(__plistToPreload[plistIndex]);
                
                setLoadingLabel();
                
                (*taskIndex)++;
            });
        }
        
        
        for (int j = 0; j < soundCount; ++j)
        {
            std::shared_ptr<bool> isDestroyed = _isDestroyed;
            AudioEngine::preload(__soundToPreload[j], [=](bool isSucceed) {
                if (*isDestroyed)
                {
                    return;
                }
                
                setLoadingLabel();
                (*taskIndex)++;
            });
        }
        
        return true;
    }

    return false;
}

void ScenarioTest::performTests()
{
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesMoved = CC_CALLBACK_2(ScenarioTest::onTouchesMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    _particleNumber = _initParticleNum;

    // get the window size & origin position
    auto s = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    // add tile map
    _map1 = cocos2d::TMXTiledMap::create("TileMaps/iso-test.tmx");
    _map1->setAnchorPoint( Vec2(0.5, 0.5) );
    _map1->setPosition(origin);
    this->addChild(_map1);

    _map2 = cocos2d::TMXTiledMap::create("TileMaps/iso-test2.tmx");
    _map2->setAnchorPoint( Vec2(0.5, 0.5) );
    _map2->setPosition(origin);
    this->addChild(_map2);

    // add toggle menu item
    MenuItemFont::setFontSize(20);
//    _itemToggle = MenuItemToggle::createWithCallback(nullptr,
//                                                    MenuItemFont::create( "Add/Remove Sprite" ),
//                                                    MenuItemFont::create( "Add/Remove Particle"),
//                                                    MenuItemFont::create( "Add/Remove Particle System"),
//                                                    nullptr);
//    _itemToggle->setAnchorPoint(Vec2(0.0f, 0.5f));
//    _itemToggle->setPosition(Vec2(origin.x, origin.y + s.height / 2));
//
    // add decrease & increase menu item
    MenuItemFont::setFontSize(100);
    auto decrease = MenuItemFont::create(" - ", [&](Ref *sender) {
        removeSprites();
        removeParticles();
        removeParticleSystem();
        
//		int idx = _itemToggle->getSelectedIndex();
//        switch (idx) {
//        case 0:
//            removeSprites();
//            break;
//        case 1:
//            removeParticles();
//            break;
//        case 2:
//            removeParticleSystem();
//            break;
//        default:
//            break;
//        }
	});
    decrease->setPosition(Vec2(origin.x + s.width / 2 - 80, origin.y + 80));
    decrease->setColor(Color3B(0,200,20));
    auto increase = MenuItemFont::create(" + ", [&](Ref *sender) {
        addNewSprites(_spriteStepNum);
        addParticles(_parStepNum);
        addParticleSystem(_parsysStepNum);
        
//		int idx = _itemToggle->getSelectedIndex();
//        switch (idx) {
//        case 0:
//            addNewSprites(_spriteStepNum);
//            break;
//        case 1:
//            addParticles(_parStepNum);
//            break;
//        case 2:
//            addParticleSystem(_parsysStepNum);
//            break;
//        default:
//            break;
//        }
	});
    increase->setColor(Color3B(0,200,20));
    increase->setPosition(Vec2(origin.x + s.width / 2 + 80, origin.y + 80));
    
    auto menu = Menu::create(/*_itemToggle, */decrease, increase, nullptr);
    menu->setPosition(Vec2(0.0f, 0.0f));
    addChild(menu, 10);

    
    // add tip labels
    _spriteLabel = Label::createWithTTF("Sprites : 0", "fonts/arial.ttf", 15);
    _spriteLabel->setAnchorPoint(Vec2(0.0f, 0.5f));
    addChild(_spriteLabel, 10);
    _spriteLabel->setPosition(Vec2(origin.x, origin.y + s.height/2 + 70));
    
    char str[32] = { 0 };
    sprintf(str, "Particles : %d", _particleNumber);
    _particleLabel = Label::createWithTTF(str, "fonts/arial.ttf", 15);
    _particleLabel->setAnchorPoint(Vec2(0.0f, 0.5f));
    addChild(_particleLabel, 10);
    _particleLabel->setPosition(Vec2(origin.x, origin.y + s.height/2 + 45));
    
    _parsysLabel = Label::createWithTTF("Particle System : 0", "fonts/arial.ttf", 15);
    _parsysLabel->setAnchorPoint(Vec2(0.0f, 0.5f));
    addChild(_parsysLabel, 10);
    _parsysLabel->setPosition(Vec2(origin.x, origin.y + s.height/2 + 20));

    // add sprites
    addNewSprites(_initSpriteNum);
    
    // add particle system
    addParticleSystem(_initParsysNum);
}

void ScenarioTest::onTouchesMoved(const std::vector<Touch*>& touches, Event  *event)
{
    auto touch = touches[0];
    
    auto diff = touch->getDelta();
    auto currentPos1 = _map1->getPosition();
    _map1->setPosition(currentPos1 + diff);
    
    auto currentPos2 = _map2->getPosition();
    _map2->setPosition(currentPos2 + diff);
}

void ScenarioTest::addParticles(int num)
{
    _particleNumber += num;

    for (auto par : _parsysArray) {
        par->setTotalParticles(_particleNumber);
    }

    char str[25] = { 0 };
    sprintf(str, "Particles : %d", _particleNumber);
    _particleLabel->setString(str);
}

void ScenarioTest::removeParticles()
{
    if (_particleNumber <= 0) {
        return;
    }
    
    int removeNum = MIN(_particleNumber, _parStepNum);
    _particleNumber -= removeNum;

    for (auto par : _parsysArray) {
        par->setTotalParticles(_particleNumber);
    }

    char str[25] = { 0 };
    sprintf(str, "Particles : %d", _particleNumber);
    _particleLabel->setString(str);
}

void ScenarioTest::addNewSprites(int num)
{
    auto s = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    for (int i = 0; i < num; ++i) {
        int idx = (int)(CCRANDOM_0_1() * 1400.0f / 100.0f);
        int x = (idx%5) * 85;
        int y = (idx/5) * 121;

        auto sprite = Sprite::create("Images/grossini_dance_atlas.png", Rect(x,y,85,121) );
        addChild( sprite );
        
        float randomx = CCRANDOM_0_1();
        float randomy = CCRANDOM_0_1();
        sprite->setPosition(origin + Vec2(randomx * s.width, randomy * s.height));
        
        ActionInterval* action;
        float random = CCRANDOM_0_1();
        
        if( random < 0.20 )
            action = ScaleBy::create(3, 2);
        else if(random < 0.40)
            action = RotateBy::create(3, 360);
        else if( random < 0.60)
            action = Blink::create(1, 3);
        else if( random < 0.8 )
            action = TintBy::create(2, 0, -255, -255);
        else
            action = FadeOut::create(2);
        auto action_back = action->reverse();
        auto seq = Sequence::create( action, action_back, nullptr );
        
        sprite->runAction( RepeatForever::create(seq) );

        _spriteArray.pushBack(sprite);
    }

    char str[20] = {0};
    sprintf(str, "Sprites : %d", (int)_spriteArray.size());
    _spriteLabel->setString(str);
}

void ScenarioTest::removeSprites()
{
    ssize_t number = _spriteArray.size();
    if (number <= 0) {
        return;
    }

    ssize_t removeNum = MIN(number, _spriteStepNum);
    for (int i = 0; i < removeNum; ++i) {
        auto sprite = _spriteArray.getRandomObject();
        removeChild(sprite);
        _spriteArray.eraseObject(sprite);
    }
    
    char str[20] = {0};
    sprintf(str, "Sprites : %d", (int)_spriteArray.size());
    _spriteLabel->setString(str);
}

static const std::string _particleFiles[] = {
    "Particles/BoilingFoam.plist",
    "Particles/Galaxy.plist",
    "Particles/SmallSun.plist",
    "Particles/lines.plist",
    "Particles/Comet.plist",
    "Particles/LavaFlow.plist",
    "Particles/SpinningPeas.plist",
    "Particles/Flower.plist",
    "Particles/Phoenix.plist",
    "Particles/debian.plist",
};
void ScenarioTest::addParticleSystem(int num)
{
    int filesSize = sizeof(_particleFiles) / sizeof(std::string);
    auto s = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    for (int i = 0; i < num; ++i)
    {
        float randomIdx = CCRANDOM_0_1();
        int idx = (filesSize - 1) * randomIdx;
        std::string fileName = _particleFiles[idx];
        auto par = ParticleSystemQuad::create(fileName);

        float randomx = CCRANDOM_0_1();
        float randomy = CCRANDOM_0_1();
        par->setPosition(origin + Vec2(s.width * randomx, s.height * randomy));
        par->setTotalParticles(_particleNumber);
        addChild(par, 9);

        _parsysArray.pushBack(par);
    }

    char str[40] = {0};
    sprintf(str, "Particle System : %d", (int)_parsysArray.size());
    _parsysLabel->setString(str);
}

void ScenarioTest::removeParticleSystem()
{
    ssize_t number = _parsysArray.size();
    if (number <= 0) {
        return;
    }
    
    ssize_t removeNum = MIN(number, _parsysStepNum);
    for (int i = 0; i < removeNum; ++i) {
        auto par = _parsysArray.getRandomObject();
        removeChild(par);
        _parsysArray.eraseObject(par);
    }
    
    char str[40] = {0};
    sprintf(str, "Particle System : %d", (int)_parsysArray.size());
    _parsysLabel->setString(str);
}

void ScenarioTest::onEnter()
{
    TestCase::onEnter();
    
    if (isAutoTesting()) {
        autoTestIndex = 0;
        Profile::getInstance()->testCaseBegin("ScenarioTest",
                                              genStrVector("SpriteCount", "ParticleCount", "ParticleSystemCount", nullptr),
                                              genStrVector("Avg", "Min", "Max", nullptr));
        doAutoTest();
        scheduleUpdate();
    }
}

void ScenarioTest::onExit()
{
    Director::getInstance()->getScheduler()->unscheduleAllForTarget(this);
    TestCase::onExit();
}

void ScenarioTest::update(float dt)
{
    if (isStating) {
        totalStatTime += dt;
        statCount++;
        
        auto curFrameRate = Director::getInstance()->getFrameRate();
        if (maxFrameRate < 0 || curFrameRate > maxFrameRate)
            maxFrameRate = curFrameRate;
        
        if (minFrameRate < 0 || curFrameRate < minFrameRate)
            minFrameRate = curFrameRate;
    }
}

void ScenarioTest::beginStat(float dt)
{
    unschedule(CC_SCHEDULE_SELECTOR(ScenarioTest::beginStat));
    isStating = true;
}

void ScenarioTest::endStat(float dt)
{
    unschedule(CC_SCHEDULE_SELECTOR(ScenarioTest::endStat));
    isStating = false;
    
    // record test data
    auto avgStr = genStr("%.2f", (float) statCount / totalStatTime);
    Profile::getInstance()->addTestResult(genStrVector(genStr("%d", _spriteArray.size()).c_str(),
                                                       genStr("%d", _particleNumber).c_str(),
                                                       genStr("%d", _parsysArray.size()).c_str(),
                                                       nullptr),
                                          genStrVector(avgStr.c_str(), genStr("%.2f", minFrameRate).c_str(),
                                                       genStr("%.2f", maxFrameRate).c_str(), nullptr));

    // check the auto test is end or not
    int autoTestCount = sizeof(autoTestCounts) / sizeof(TestCaseInfo);
    if (autoTestIndex >= (autoTestCount - 1))
    {
        // auto test end
        Profile::getInstance()->testCaseEnd();
        setAutoTesting(false);
        return;
    }

    autoTestIndex++;
    doAutoTest();
}

void ScenarioTest::doAutoTest()
{
    isStating = false;
    statCount = 0;
    totalStatTime = 0.0f;
    minFrameRate = -1.0f;
    maxFrameRate = -1.0f;
    
    // remove all nodes
    while (_spriteArray.size() > 0) {
        removeSprites();
    }
    while (_parsysArray.size() > 0) {
        removeParticleSystem();
    }
    
    // add nodes
    auto caseInfo = autoTestCounts[autoTestIndex];
    _particleNumber = 0;
    addNewSprites(caseInfo.spriteCount);
    addParticleSystem(caseInfo.particleSystemCount);
    addParticles(caseInfo.particleCount);

    schedule(CC_SCHEDULE_SELECTOR(ScenarioTest::beginStat), DELAY_TIME);
    schedule(CC_SCHEDULE_SELECTOR(ScenarioTest::endStat), DELAY_TIME + STAT_TIME);
}

std::string ScenarioTest::title() const
{
    return "CPU & GPU Test";
}

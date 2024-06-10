#pragma once
#include "Utils.h"
#include "Vector.h"
#include <boost/python.hpp>
#include <boost/python/suite/indexing/map_indexing_suite.hpp>

using namespace boost::python;

/// Defines the mapping between the C++ and Python classes
BOOST_PYTHON_MODULE(Vippro)
{
    class_<Vector2>("Vector2", init<float, float>())
        .def_readwrite("x", &Vector2::x)
        .def_readwrite("y", &Vector2::y)
        .def("length", &Vector2::length)
        .def("distance", &Vector2::distance)
        .def("distance_squared", &Vector2::distance_squared)
        .def("scale", &Vector2::vscale)
        .def("scale", &Vector2::scale)
        .def("normalize", &Vector2::normalize)
        .def("add", &Vector2::add)
        .def("sub", &Vector2::sub)
        .def("clone", &Vector2::clone);

    class_<Vector3>("Vector3", init<float, float, float>())
        .def_readwrite("x", &Vector3::x)
        .def_readwrite("y", &Vector3::y)
        .def_readwrite("z", &Vector3::z)
        .def("length", &Vector3::length)
        .def("distance", &Vector3::distance)
        .def("distance_squared", &Vector3::distance_squared)
        .def("rotate_x", &Vector3::rotate_x)
        .def("rotate_y", &Vector3::rotate_y)
        .def("rotate_z", &Vector3::rotate_z)
        .def("scale", &Vector3::vscale)
        .def("scale", &Vector3::scale)
        .def("normalize", &Vector3::normalize)
        .def("add", &Vector3::add)
        .def("sub", &Vector3::sub)
        .def("clone", &Vector3::clone)
        .def("extend", &Vector3::extend);

    class_<Vector4>("Vector4", init<float, float, float, float>())
        .def_readwrite("x", &Vector4::x)
        .def_readwrite("y", &Vector4::y)
        .def_readwrite("z", &Vector4::z)
        .def_readwrite("w", &Vector4::w)
        .def("length", &Vector4::length)
        .def("distance", &Vector4::distance)
        .def("distance_squared", &Vector4::distance_squared)
        .def("scale", &Vector4::vscale)
        .def("scale", &Vector4::scale)
        .def("normalize", &Vector4::normalize)
        .def("add", &Vector4::add)
        .def("sub", &Vector4::sub)
        .def("clone", &Vector4::clone);

    class_<AIManagerInfo>("AIManagerInfo")
        .def_readonly("startPath", &AIManagerInfo::startPath)
        .def_readonly("endPath", &AIManagerInfo::endPath)
        .def_readonly("isMoving", &AIManagerInfo::isMoving)
        .def_readonly("isDashing", &AIManagerInfo::isDashing)
        .def_readonly("targetPath", &AIManagerInfo::GetTargetPath)
        .def_readonly("velocity", &AIManagerInfo::velocity)
        .def_readonly("serverPos", &AIManagerInfo::serverPos)
        .def_readonly("moveSpeed", &AIManagerInfo::moveSpeed)
        .def_readonly("dashSpeed", &AIManagerInfo::dashSpeed);

    class_<BuffInfo>("BuffInfo")
        .def_readonly("name", &BuffInfo::name)
        .def_readonly("count", &BuffInfo::count)
        .def_readonly("countAlt", &BuffInfo::countAlt)
        .def_readonly("countAlt2", &BuffInfo::countAlt2)
        .def_readonly("type", &BuffInfo::type)
        .def_readonly("startTime", &BuffInfo::startTime)
        .def_readonly("endTime", &BuffInfo::endTime)
        .def_readonly("isAlive", &BuffInfo::isAlive);

    class_<ItemInfo>("ItemInfo")
        .def_readonly("id", &ItemInfo::id)
        .def_readonly("name", &ItemInfo::name)
        .def_readonly("cost", &ItemInfo::cost)
        .def_readonly("movementSpeed", &ItemInfo::movementSpeed)
        .def_readonly("health", &ItemInfo::health)
        .def_readonly("crit", &ItemInfo::crit)
        .def_readonly("abilityPower", &ItemInfo::abilityPower)
        .def_readonly("mana", &ItemInfo::mana)
        .def_readonly("armour", &ItemInfo::armour)
        .def_readonly("magicResist", &ItemInfo::magicResist)
        .def_readonly("physicalDamage", &ItemInfo::physicalDamage)
        .def_readonly("attackSpeed", &ItemInfo::attackSpeed)
        .def_readonly("lifeSteal", &ItemInfo::lifeSteal)
        .def_readonly("hpRegen", &ItemInfo::hpRegen)
        .def_readonly("movementSpeedPercent", &ItemInfo::movementSpeedPercent);

    class_<ItemSlot>("ItemSlot")
        .def_readonly("slot", &ItemSlot::slot)
        .def_readonly("isEmpty", &ItemSlot::isEmpty)
        .def_readonly("info", &ItemSlot::GetItemInfo);

    class_<SpellInfo>("SpellInfo")
        .def_readonly("name", &SpellInfo::name)
        .def_readonly("nameAlt", &SpellInfo::nameAlt)
        .def_readonly("icon", &SpellInfo::icon)
        .def_readonly("flags", &SpellInfo::flags)
        .def_readonly("delay", &SpellInfo::delay)
        .def_readonly("castRange", &SpellInfo::castRange)
        .def_readonly("castRadius", &SpellInfo::castRadius)
        .def_readonly("width", &SpellInfo::width)
        .def_readonly("height", &SpellInfo::height)
        .def_readonly("speed", &SpellInfo::speed)
        .def_readonly("travelTime", &SpellInfo::travelTime)
        .def_readonly("type", &SpellInfo::type)
        .def_readonly("projectDestination", &SpellInfo::projectDestination);

    class_<Missile>("Missile", init<Missile>())
        .def_readonly("name", &Missile::name)
        .def_readonly("srcIdx", &Missile::srcIdx)
        .def_readonly("team", &Missile::team)
        .def_readonly("pos", &Missile::pos)
        .def_readonly("startPos", &Missile::startPos)
        .def_readonly("endPos", &Missile::endPos)
        .def_readonly("info", &Missile::GetSpellInfo);

    enum_<SpellSlot>("SpellSlot")
        .value("Q", SpellSlot::Q)
        .value("W", SpellSlot::W)
        .value("E", SpellSlot::E)
        .value("R", SpellSlot::R)
        .value("D", SpellSlot::D)
        .value("F", SpellSlot::F);

    enum_<SummonerSpellType>("SummonerSpellType")
        .value("NONE", SummonerSpellType::NONE)
        .value("GHOST", SummonerSpellType::GHOST)
        .value("HEAL", SummonerSpellType::HEAL)
        .value("BARRIER", SummonerSpellType::BARRIER)
        .value("EXHAUST", SummonerSpellType::EXHAUST)
        .value("CLARITY", SummonerSpellType::CLARITY)
        .value("SNOWBALL", SummonerSpellType::SNOWBALL)
        .value("FLASH", SummonerSpellType::FLASH)
        .value("TELEPORT", SummonerSpellType::TELEPORT)
        .value("CLEANSE", SummonerSpellType::CLEANSE)
        .value("IGNITE", SummonerSpellType::IGNITE)
        .value("SMITE", SummonerSpellType::SMITE)
        .value("RECALL", SummonerSpellType::RECALL)
        .value("WARD", SummonerSpellType::WARD)
        .value("QSS", SummonerSpellType::QSS);

    class_<Spell>("Spell", init<SpellSlot>())
        .def_readonly("name", &Spell::name)
        .def_readonly("slot", &Spell::slot)
        .def_readonly("level", &Spell::level)
        .def_readonly("readyAt", &Spell::readyAt)
        .def_readonly("info", &Spell::GetSpellInfo)
        .def_readonly("summonerSpellType", &Spell::summonerSpellType)
        .def("GetRemainingCooldown", &Spell::GetRemainingCooldown)
        .def("IsReady", &Spell::IsReady)
        .def("Trigger", &Spell::Trigger)
        .def("MoveAndTrigger", &Spell::MoveAndTrigger)
        .def("MoveAndRelease", &Spell::MoveAndRelease)
        .def("Cast", &Spell::Cast);

    class_<LeagueRenderer>("LeagueRenderer", init<LeagueRenderer>())
        .def_readonly("width", &LeagueRenderer::width)
        .def_readonly("height", &LeagueRenderer::height);

    class_<ConfigSet>("Config")
        .def("SetInt", &ConfigSet::SetInt)
        .def("SetBool", &ConfigSet::SetBool)
        .def("SetFloat", &ConfigSet::SetFloat)
        .def("SetStr", &ConfigSet::SetStr)
        .def("GetInt", &ConfigSet::GetInt)
        .def("GetBool", &ConfigSet::GetBool)
        .def("GetFloat", &ConfigSet::GetFloat)
        .def("GetStr", &ConfigSet::GetStr);

    class_<UnitInfo>("UnitInfo")
        .def_readonly("name", &UnitInfo::name)
        .def_readonly("healthBarHeight", &UnitInfo::healthBarHeight)
        .def_readonly("baseMoveSpeed", &UnitInfo::baseMoveSpeed)
        .def_readonly("attackRange", &UnitInfo::attackRange)
        .def_readonly("attackSpeed", &UnitInfo::attackSpeed)
        .def_readonly("attackSpeedRatio", &UnitInfo::attackSpeedRatio)
        .def_readonly("acquisitionRange", &UnitInfo::acquisitionRange)
        .def_readonly("selectionRadius", &UnitInfo::selectionRadius)
        .def_readonly("pathingRadius", &UnitInfo::pathingRadius)
        .def_readonly("gameplayRadius", &UnitInfo::gameplayRadius)
        .def_readonly("basicAtkMissileSpeed", &UnitInfo::basicAtkMissileSpeed)
        .def_readonly("basicAtkWindup", &UnitInfo::basicAtkWindup)
        .def_readonly("basicAtkWindupModify", &UnitInfo::basicAtkWindupModify)
        .def_readonly("tags", &UnitInfo::tags);

    class_<GameObject>("GameObject")
        .def_readonly("objIndex", &GameObject::objIndex)
        .def_readonly("name", &GameObject::name)
        .def_readonly("networkId", &GameObject::networkId)
        .def_readonly("team", &GameObject::team)
        .def_readonly("health", &GameObject::health)
        .def_readonly("maxHealth", &GameObject::maxHealth)
        .def_readonly("position", &GameObject::position)
        .def_readonly("visible", &GameObject::visible)
        .def_readonly("targetable", &GameObject::targetable)
        .def_readonly("isAlive", &GameObject::isAlive)
        .def_readonly("armor", &GameObject::armor)
        .def_readonly("magicRes", &GameObject::magicRes)
        .def_readonly("info", &GameObject::GetUnitInfo)
        .def_readonly("address", &GameObject::address)
        .def_readonly("level", &GameObject::level)
        .def_readonly("attackRange", &GameObject::attackRange)
        .def_readonly("basicAtk", &GameObject::basicAtk)
        .def_readonly("bonusAtkSpeed", &GameObject::bonusAtkSpeed)
        .def_readonly("bonusAtk", &GameObject::bonusAtk)
        .def_readonly("abilityPower", &GameObject::abilityPower)
        .def_readonly("lethality", &GameObject::lethality)
        .def_readonly("armorPen", &GameObject::armorPen)
        .def_readonly("magicPen", &GameObject::magicPen)
        .def_readonly("magicResPen", &GameObject::magicResPen)
        .def_readonly("itemSlots", &GameObject::GetItemSlots)
        .def_readonly("Q", &GameObject::Q)
        .def_readonly("W", &GameObject::W)
        .def_readonly("E", &GameObject::E)
        .def_readonly("R", &GameObject::R)
        .def_readonly("D", &GameObject::D)
        .def_readonly("F", &GameObject::F)
        .def_readonly("buffs", &GameObject::GetBuffs)
        .def_readonly("activeCast", &GameObject::activeCast)
        .def_readonly("AIManager", &GameObject::AIManager)
        .def("__eq__", &GameObject::IsEqualTo)
        .def("__ne__", &GameObject::IsNotEqualTo)
        .def("IsAllyTo", &GameObject::IsAllyTo)
        .def("IsEnemyTo", &GameObject::IsEnemyTo)
        .def("HasUnitTags", &GameObject::HasUnitTags)
        .def("GetCastDelay", &GameObject::GetCastDelay)
        .def("GetAttackSpeed", &GameObject::GetAttackSpeed)
        .def("GetBuffByName", &GameObject::GetBuffByName, return_value_policy<reference_existing_object>())
        .def_readonly("IsHurtable", &GameObject::IsHurtable)
        .def_readonly("IsRanged", &GameObject::IsRanged);

    class_<PyGame>("Game")
        .def_readonly("champs", &PyGame::champs)
        .def_readonly("minions", &PyGame::minions)
        .def_readonly("jungles", &PyGame::jungles)
        .def_readonly("missiles", &PyGame::missiles)
        .def_readonly("others", &PyGame::others)
        .def_readonly("player", &PyGame::GetLocalChampion)
        .def_readonly("gameTime", &PyGame::gameTime)
        .def_readonly("isChatOpen", &PyGame::isChatOpen)
        .def_readonly("ping", &PyGame::ping)

        .def("GetObjectByIndex", &PyGame::GetObjectByIndex, return_value_policy<reference_existing_object>())
        .def("GetObjectByNetId", &PyGame::GetObjectByNetId, return_value_policy<reference_existing_object>())
        .def("GetBestTarget", &PyGame::GetBestTarget, return_value_policy<reference_existing_object>())

        .def("IsScreenPointOnScreen", &PyGame::IsScreenPointOnScreen, PyGame::IsScreenPointOnScreenOverloads())
        .def("IsScreenPointOnScreen", &PyGame::IsWorldPointOnScreen, PyGame::IsWorldPointOnScreenOverloads())
        .def("WorldToScreen", &PyGame::WorldToScreen)

        .def("DrawLine", &PyGame::DrawLine)
        .def("DrawLineWorld", &PyGame::DrawLineWorld)
        .def("DrawCircle", &PyGame::DrawCircle)
        .def("DrawCircleFilled", &PyGame::DrawCircleFilled)
        .def("DrawCircleWorld", &PyGame::DrawCircleWorld)
        .def("DrawCircleWorldFilled", &PyGame::DrawCircleWorldFilled)
        .def("DrawTxt", &PyGame::DrawTxt)
        .def("DrawRect", &PyGame::DrawRect, PyGame::DrawRectOverloads())
        .def("DrawRectFilled", &PyGame::DrawRectFilled, PyGame::DrawRectFilledOverloads())
        .def("DrawRectWorld", &PyGame::DrawRectWorld)
        .def("DrawRectFromPos", &PyGame::DrawRectFromPos)
        .def("DrawTriangleWorld", &PyGame::DrawTriangleWorld)
        .def("DrawTriangleWorldFilled", &PyGame::DrawTriangleWorldFilled)
        .def("DrawButton", &PyGame::DrawButton, PyGame::DrawButtonOverloads())

        .def("GetSpellInfo", &PyGame::GetSpellInfo, return_value_policy<reference_existing_object>())

        .def("clamp2d", &PyGame::clamp_norm_2d)
        .def("isLeft", &PyGame::isLeft)
        .def("PointOnLineSegment", &PyGame::PointOnLineSegment)
        .def("isPointOnLineSegment", &PyGame::isPointOnLineSegment)

        .def("MoveCursor", &PyGame::MoveCursor)
        .def("WasKeyPressed", &PyGame::WasKeyPressed)
        .def("IsKeyDown", &PyGame::IsKeyDown)
        .def("PressKey", &PyGame::PressKey)
        .def("KeyDown", &PyGame::KeyDown)
        .def("KeyUp", &PyGame::KeyUp)
        .def("PressLeftClick", &PyGame::PressLeftClick)
        .def("PressRightClick", &PyGame::PressRightClick)
        .def("MouseLeftDown", &PyGame::MouseLeftDown)
        .def("MouseLeftUp", &PyGame::MouseLeftUp)
        .def("MouseRightDown", &PyGame::MouseRightDown)
        .def("MouseRightUp", &PyGame::MouseRightUp)
        .def("ClickAt", &PyGame::ClickAt)
        .def("GetCursor", &PyGame::GetCursor);

    class_<PyImguiInterface>("UI")
        .def("Begin", &PyImguiInterface::Begin)
        .def("End", &PyImguiInterface::End)

        .def("Button", &PyImguiInterface::Button)
        .def("ColorButton", &PyImguiInterface::ColorButton)
        .def("ColorPicker", &PyImguiInterface::ColorPicker)
        .def("Checkbox", &PyImguiInterface::Checkbox)
        .def("Text", &PyImguiInterface::Text)
        .def("Text", &PyImguiInterface::TextColored)
        .def("LabelText", &PyImguiInterface::LabelText)
        .def("LabelText", &PyImguiInterface::LabelTextColored)
        .def("Separator", &PyImguiInterface::Separator)
        .def("DragInt", &PyImguiInterface::DragInt, PyImguiInterface::DragIntOverloads())
        .def("DragFloat", &PyImguiInterface::DragFloat, PyImguiInterface::DragFloatOverloads())
        .def("KeySelect", &PyImguiInterface::KeySelect)
        .def("SliderFloat", &PyImguiInterface::SliderFloat)
        .def("SliderInt", &PyImguiInterface::SliderInt)

        .def("CollapsingHeader", &PyImguiInterface::CollapsingHeader)
        .def("TreeNode", &PyImguiInterface::TreeNode)
        .def("TreePop", &PyImguiInterface::TreePop)
        .def("SetNextItemOpen", &PyImguiInterface::SetNextItemOpen)

        .def("SameLine", &PyImguiInterface::SameLine)
        .def("BeginGroup", &PyImguiInterface::BeginGroup)
        .def("EndGroup", &PyImguiInterface::EndGroup)

        .def("ListBox", &PyImguiInterface::ListBox);

    class_<ImVec4>("Colors", init<float, float, float, float>())
        .def_readonly("BLACK", &Colors::BLACK)
        .def_readonly("WHITE", &Colors::WHITE)
        .def_readonly("RED", &Colors::RED)
        .def_readonly("DARK_RED", &Colors::DARK_RED)
        .def_readonly("GREEN", &Colors::GREEN)
        .def_readonly("DARK_GREEN", &Colors::DARK_GREEN)
        .def_readonly("YELLOW", &Colors::YELLOW)
        .def_readonly("DARK_YELLOW", &Colors::DARK_YELLOW)
        .def_readonly("CYAN", &Colors::CYAN)
        .def_readonly("PURPLE", &Colors::PURPLE)
        .def_readonly("GRAY", &Colors::GRAY)
        .def_readonly("ORANGE", &Colors::ORANGE)
        .def_readonly("BLUE", &Colors::BLUE)
        .def_readonly("BROWN", &Colors::BROWN)
        .def_readwrite("r", &ImVec4::x)
        .def_readwrite("g", &ImVec4::y)
        .def_readwrite("b", &ImVec4::z)
        .def_readwrite("a", &ImVec4::w);
}
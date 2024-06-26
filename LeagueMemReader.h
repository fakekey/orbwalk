#pragma once
#include "MemSnapShot.h"
#include "windows.h"
#include <set>
#include <string>

class LeagueMemReader {
public:
    LeagueMemReader();

    /// Checks if leagues window is still active
    bool IsLeagueWindowActive();

    /// Checks to see if we have a league window stored
    bool IsHookedToProcess();

    /// Finds leagues window and stores it
    void HookToProcess();

    /// Creates an object with everything of iterest from the game
    void MakeSnapShot(MemSnapShot& ms);

    float gameTime = 0.0f;

private:
    // Memory related
    DWORD_PTR moduleBaseAddr = 0;

private:
    /// Blacklisted objects that we don't need to read for performance reasons. Set key is the object's network id
    std::set<int> blacklistedObjects;
    std::set<std::string> blacklistedObjectNames;

    void ReadRenderer(MemSnapShot& snapshot);
    void ReadChampions(MemSnapShot& snapshot);
    void ReadMinions(MemSnapShot& snapshot);
    void ReadMissiles(MemSnapShot& snapshot);
    void FindLocalPlayer(MemSnapShot& snapshot);
    void ClearMissingObjects(MemSnapShot& snapshot);
};
#pragma once
#include "KTileManager.h"
#include <map>
#include <vector>
#include "KVector2.h"

struct Animation
{
    std::vector<KVector2> sequence;
    double timeBetweenFrames;
    double elapsedTime = 0.0;
    int currentFrame = 0;
};

class KSpriteAnimator
{
private:
    KTileManager* _tilemap = nullptr;
    std::map<int, Animation> _animations;

public:
    void SetTilemap(KTileManager* tilemap)
    {
        _tilemap = tilemap;
    }

    void SetAnimation(int id, const std::vector<KVector2>& sequence, double timeBetweenSprite)
    {
        Animation anim;
        anim.sequence = sequence;
        anim.timeBetweenFrames = timeBetweenSprite;
        _animations[id] = anim;
    }

    void Update(double deltaTime)
    {
        for (std::map<int, Animation>::iterator it = _animations.begin(); it != _animations.end(); ++it) {
            Animation& anim = it->second;
            anim.elapsedTime += deltaTime;
            if (anim.elapsedTime >= anim.timeBetweenFrames) {
                anim.elapsedTime = 0.0;
                anim.currentFrame = (anim.currentFrame + 1) % anim.sequence.size();
            }
        }
    }

    void Draw(HDC hdc, int id, int x, int y, bool mirror = false, double scale = 1.0)
    {
        if (_animations.find(id) == _animations.end() || !_tilemap) return;
        const Animation& anim = _animations[id];
        const KVector2& tile = anim.sequence[anim.currentFrame];
        _tilemap->DrawTile(hdc, x, y, (int)tile.y, (int)tile.x, mirror, scale);
    }

    void ClearAll()
    {
        _animations.clear();
    }
};

#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <Node.hpp>
#include <Node2D.hpp>
#include <Sprite.hpp>
#include <AnimationPlayer.hpp>
#include <Input.hpp>
#include <Vector2.hpp>
#include <Area2D.hpp>
#include <algorithm>
#include <limits>
#include <CollisionShape2D.hpp>
#include <KinematicBody2D.hpp>

namespace godot {
  enum class DIRECTION { NORTH, SOUTH, EAST, WEST };

  class Player : public KinematicBody2D {
    GODOT_CLASS(Player, KinematicBody2D)

  public:
    int speed;
    int gravity;
    int jump_force;

    Player();
    ~Player();
    static void _register_methods();
    void _init();
    void _process(float delta);
    void _ready();


  private:
    Sprite *sprite;
    AnimationPlayer *animation;
    Vector2 screen_size;
    Vector2 velocity;
    CollisionShape2D *collider;
    DIRECTION direction;

    bool jumping = false;

  };

}

#endif

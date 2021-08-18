#pragma once
#include "MEE_Components.h"
#include "MEE_PCH.h"
#include "MEE_Sprite.h"
#include "MEE_Drawable.h"

namespace MEE
{
	class Drawable;

	class MEE_EXPORT Animation
	{
	public:
		Animation(const SpriteSheet& ss);
		std::weak_ptr<Sprite> GetFrame();
		void NextFrame();
		void PrevFrame();
		void ResetAnim();
	private:
		std::shared_ptr<SpriteSheet> sprites;
		int currentFrame;
	};

	enum class MEE_EXPORT AnimationDirection
	{
		Forward, Backwards
	};

	class MEE_EXPORT AnimationPlayer : public Component, public Updatable
	{
	public:
		AnimationPlayer(Drawable& drawable);
		void PlayAnimation(const std::string&);
		void SetDefaultAnimation(const std::string&);
		void ResetCurrentAnim();
		void ResetPlayer();
		void Pause();
		void Resume();
		void SetAnimationFrameDuaration(int);
		virtual void Update() override;
		void UpdateAnimation(AnimationDirection direction = AnimationDirection::Forward);
		void AddAnimation(const std::string&, Animation);
	private:
		Drawable& drawObject;
		std::map <std::string, std::shared_ptr<Animation>> animations;
		std::string currentAnimation;
		std::string defaultAnimation;
		bool isPaused = false;
		int frameDuration = 1;
		int elapsedFrames = -1;

		friend class Object;
	};
}



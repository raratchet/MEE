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
		bool GetShouldLoop();
		void SetFrameDuration(int frame, int duration);
		void SetShouldLoop(bool loop);
		bool HasEnded();
	private:
		std::shared_ptr<SpriteSheet> sprites;
		std::vector<int> frameDuration;
		bool shouldLoop = true;
		bool animationEnded = false;
		int currentFrame;
		int currentFrameRepetition;
		friend class AnimationPlayer;
	};

	enum class MEE_EXPORT AnimationDirection
	{
		Forward, Backwards
	};

	class MEE_EXPORT AnimationPlayer : public Component, public Updatable
	{
	public:
		AnimationPlayer(Drawable& drawable);
		Animation& GetCurrentAnimation();
		Animation& GetAnimation(const std::string& anim);
		void PlayAnimation(const std::string&);
		void SetDefaultAnimation(const std::string&);
		void ResetCurrentAnim();
		void ResetPlayer();
		void Pause();
		void Resume();
		void SetAnimationFrameDuration(int duration);
		void SetFramesPerSecond(int frames);
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
		int framesPerSecond = 2;
		int elapsedFrames = -1;

		friend class Object;
	};
}



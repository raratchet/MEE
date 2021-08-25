#include "MEE_Animation.h"

namespace MEE
{

	Animation::Animation(const SpriteSheet& ss) 
	{
		sprites = std::make_shared<SpriteSheet>(ss);

		for (int i = 0; i < sprites->GetNumberOfFrames(); i++)
		{
			frameDuration.push_back(1);
		}

		currentFrame = 0;
		currentFrameRepetition = 0;
	}

	std::weak_ptr<Sprite> Animation::GetFrame()
	{
		return sprites->Get(currentFrame); 
	}

	void Animation::NextFrame()
	{
		if (currentFrame < sprites->GetNumberOfFrames() - 1)
		{
			currentFrameRepetition++;
			if(currentFrameRepetition >= frameDuration[currentFrame])
				currentFrame++;
		}
		else
		{
			if (shouldLoop)
			{
				currentFrame = 0;
				currentFrameRepetition = 0;
				animationEnded = false;
			}
			else
			{
				animationEnded = true;
			}
		}
	}

	void Animation::PrevFrame()
	{
		if (currentFrame > 0)
			currentFrame --;
		else
		{
			currentFrame = sprites->GetNumberOfFrames();
			currentFrameRepetition = 0;
		}
	}

	void Animation::ResetAnim()
	{
		currentFrame = 0;
		currentFrameRepetition = 0;
		animationEnded = false;
	}

	bool Animation::GetShouldLoop()
	{
		return shouldLoop;
	}

	void Animation::SetFrameDuration(int frame, int duration)
	{
		frameDuration[frame] = duration;
	}

	void Animation::SetShouldLoop(bool loop)
	{
		shouldLoop = loop;
	}

	bool Animation::HasEnded()
	{
		return animationEnded;
	}


	AnimationPlayer::AnimationPlayer(Drawable& drawable) : drawObject(drawable)
	{
	}

	Animation& AnimationPlayer::GetCurrentAnimation()
	{
		return *animations[currentAnimation].get();
	}

	Animation& AnimationPlayer::GetAnimation(const std::string& anim)
	{
		return *animations[anim].get();
	}

	void AnimationPlayer::PlayAnimation(const std::string& anim)
	{
		if (currentAnimation != anim)
		{
			animations[currentAnimation]->animationEnded = true;
			currentAnimation = anim;
			ResetCurrentAnim();
			drawObject.SetSprite(animations[currentAnimation]->GetFrame());
		}
	}

	void AnimationPlayer::SetDefaultAnimation(const std::string& anim)
	{
		defaultAnimation = anim;
	}

	void AnimationPlayer::ResetCurrentAnim()
	{
		animations[currentAnimation]->ResetAnim();
		elapsedFrames = 0;
	}

	void AnimationPlayer::ResetPlayer()
	{
		currentAnimation = defaultAnimation;
		animations[currentAnimation]->ResetAnim();
	}

	void AnimationPlayer::Pause()
	{
		isPaused = true;
	}

	void AnimationPlayer::Resume()
	{
		isPaused = false;
	}

	void AnimationPlayer::SetAnimationFrameDuration(int val)
	{
		frameDuration = val;
	}

	void AnimationPlayer::SetFramesPerSecond(int frames)
	{
		framesPerSecond = frames;
	}

	void AnimationPlayer::UpdateAnimation(AnimationDirection direction)
	{
		if (!animations.empty())
		{
			if (elapsedFrames >= frameDuration)
			{
				if (!isPaused)
				{
					elapsedFrames = 0;
					animations[currentAnimation]->NextFrame(); //Check direction and check if the frame should move
					drawObject.SetSprite(animations[currentAnimation]->GetFrame());

				}
			}
				elapsedFrames++;
		}
			

	}

	void AnimationPlayer::Update()
	{
		UpdateAnimation();
	}

	void AnimationPlayer::AddAnimation(const std::string& name, Animation anim)
	{
		bool firstAnimation = false;

		if (animations.empty())
		{
			currentAnimation = name;
			defaultAnimation = name;
			firstAnimation = true;
		}

		animations.insert({ name,std::make_shared<Animation>(anim)});

		if(firstAnimation)
			drawObject.SetSprite(animations[currentAnimation]->GetFrame());
	}

}

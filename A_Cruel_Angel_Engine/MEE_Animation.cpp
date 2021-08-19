#include "MEE_Animation.h"

namespace MEE
{

	Animation::Animation(const SpriteSheet& ss) 
	{
		sprites = std::make_shared<SpriteSheet>(ss);
		currentFrame = -1;
	}

	std::weak_ptr<Sprite> Animation::GetFrame()
	{
		return sprites->Get(currentFrame); 
	}

	void Animation::NextFrame()
	{
		if (currentFrame < sprites->GetNumberOfFrames() - 1)
			currentFrame++;
		else
			currentFrame = 0;
	}

	void Animation::PrevFrame()
	{
		if (currentFrame > 0)
			currentFrame --;
		else
			currentFrame = sprites->GetNumberOfFrames();
	}

	void Animation::ResetAnim()
	{
		currentFrame = 0;
	}


	AnimationPlayer::AnimationPlayer(Drawable& drawable) : drawObject(drawable)
	{
	}

	void AnimationPlayer::PlayAnimation(const std::string& anim)
	{
		currentAnimation = anim;
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

	void AnimationPlayer::SetAnimationFrameDuaration(int val)
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
		if (animations.empty())
		{
			currentAnimation = name;
			defaultAnimation = name;
		}

		animations.insert({ name,std::make_shared<Animation>(anim) });
	}

}

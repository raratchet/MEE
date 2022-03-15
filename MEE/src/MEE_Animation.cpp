#include "MEE_Animation.h"
namespace MEE
{

	Animation::Animation(const SpriteSheet& ss) 
	{
        m_sprites = std::make_shared<SpriteSheet>(ss);

		for (int i = 0; i < m_sprites->GetNumberOfFrames(); i++)
		{
			m_frameDuration.push_back(1);
		}

        m_currentFrame = 0;
        m_currentFrameRepetition = 0;
	}

	std::weak_ptr<Sprite> Animation::GetFrame()
	{
		return m_sprites->Get(m_currentFrame);
	}

	void Animation::NextFrame()
	{
		if (m_currentFrame < m_sprites->GetNumberOfFrames() - 1)
		{
			m_currentFrameRepetition++;
			if(m_currentFrameRepetition >= m_frameDuration[m_currentFrame])
				m_currentFrame++;
		}
		else
		{
			if (m_shouldLoop)
			{
                m_currentFrame = 0;
                m_currentFrameRepetition = 0;
                m_animationEnded = false;
			}
			else
			{
                m_animationEnded = true;
			}
		}
	}

	void Animation::PrevFrame()
	{
		if (m_currentFrame > 0)
			m_currentFrame --;
		else
		{
            m_currentFrame = m_sprites->GetNumberOfFrames();
            m_currentFrameRepetition = 0;
		}
	}

	void Animation::ResetAnim()
	{
        m_currentFrame = 0;
        m_currentFrameRepetition = 0;
        m_animationEnded = false;
	}

	bool Animation::GetShouldLoop()
	{
		return m_shouldLoop;
	}

	void Animation::SetFrameDuration(int frame, int duration)
	{
        m_frameDuration[frame] = duration;
	}

	void Animation::SetShouldLoop(bool loop)
	{
        m_shouldLoop = loop;
	}

	bool Animation::HasEnded()
	{
		return m_animationEnded;
	}


	AnimationPlayer::AnimationPlayer(Drawable& drawable) : m_drawObject(drawable)
	{
	}

	Animation& AnimationPlayer::GetCurrentAnimation()
	{
		return *m_animations[m_currentAnimation].get();
	}

	Animation& AnimationPlayer::GetAnimation(const std::string& anim)
	{
		return *m_animations[anim].get();
	}

	void AnimationPlayer::PlayAnimation(const std::string& anim)
	{
		if (m_currentAnimation != anim)
		{
            m_animations[m_currentAnimation]->m_animationEnded = true;
            m_currentAnimation = anim;
			ResetCurrentAnim();
			m_drawObject.SetSprite(m_animations[m_currentAnimation]->GetFrame());
		}
	}

	void AnimationPlayer::SetDefaultAnimation(const std::string& anim)
	{
        m_defaultAnimation = anim;
	}

	void AnimationPlayer::ResetCurrentAnim()
	{
		m_animations[m_currentAnimation]->ResetAnim();
        m_elapsedFrames = 0;
	}

	void AnimationPlayer::ResetPlayer()
	{
        m_currentAnimation = m_defaultAnimation;
		m_animations[m_currentAnimation]->ResetAnim();
	}

	void AnimationPlayer::Pause()
	{
        m_isPaused = true;
	}

	void AnimationPlayer::Resume()
	{
        m_isPaused = false;
	}

	void AnimationPlayer::SetAnimationFrameDuration(int val)
	{
        m_frameDuration = val;
	}

	void AnimationPlayer::SetFramesPerSecond(int frames)
	{
        m_framesPerSecond = frames;
	}

	void AnimationPlayer::UpdateAnimation(AnimationDirection direction)
	{
		if (!m_animations.empty())
		{
			if (m_elapsedFrames >= m_frameDuration)
			{
				if (!m_isPaused)
				{
                    m_elapsedFrames = 0;
					m_animations[m_currentAnimation]->NextFrame(); //Check direction and check if the frame should move
					m_drawObject.SetSprite(m_animations[m_currentAnimation]->GetFrame());

				}
			}
				m_elapsedFrames++;
		}
			

	}

	void AnimationPlayer::Update()
	{
		UpdateAnimation();
	}

	void AnimationPlayer::AddAnimation(const std::string& name, Animation anim)
	{
		bool firstAnimation = false;

		if (m_animations.empty())
		{
            m_currentAnimation = name;
            m_defaultAnimation = name;
			firstAnimation = true;
		}

		m_animations.insert({name, std::make_shared<Animation>(anim)});

		if(firstAnimation)
			m_drawObject.SetSprite(m_animations[m_currentAnimation]->GetFrame());
	}

}

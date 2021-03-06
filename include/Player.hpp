#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Engine.hpp"
#include "Camera.hpp"

class Player
{
public:
	Player(glm::vec3 pos, glm::vec3 rot, Engine* engine);

	/*
		Sets the players position
	*/
	void SetPosition(glm::vec3 pos);

	/*
		Returns the players position
	*/
	glm::vec3 GetPosition();

	/*
		Sets the players rotation
	*/
	void SetRotation(glm::vec3 rot);

	/*
		Returns the players rotation
	*/
	glm::vec3 GetRotation();

	/*
		Updates the Players position
	*/
	void Update(bool mousein);

	/*
		Returns the camera Class used by the player
	*/
	Camera* GetCamera() { return m_Camera; }

private:
	// Rendering Engine
	Engine* m_pEngine;

	// Player position
	glm::vec3 m_pos;

	// Player rotation
	glm::vec3 m_rot;

	// Camera Class
	Camera* m_Camera;
};

#endif // PLAYER_HPP
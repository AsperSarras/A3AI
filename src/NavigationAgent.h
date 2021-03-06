#pragma once
#ifndef _NAVIGATION_AGENT_
#define _NAVIGATION_AGENT_
#include <GLM/detail/type_vec4.hpp>

#include "DisplayObject.h"

class NavigationAgent :public DisplayObject
{
public:
	NavigationAgent();

	~NavigationAgent();

	virtual void draw() override = 0;
	virtual void update() override = 0;
	virtual void clean() override = 0;

	glm::vec2 getGridPosition() const;
	void setGridPosition(float col, float row);

	glm::vec2 getOrientation() const { return m_orientation; }
	void setOrientation(glm::vec2 orientation) { m_orientation = orientation; }

	float getLOSDistance() const;
	bool hasLOS()const;
	glm::vec4 getLOSColour()const;

	float getCloseCombatDistance() const;
	bool isInCloseCombatDistance() const;
	glm::vec4 getCloseCombatColour()const;

	void setLOSDistance(float distance);
	void setHasLOS(bool state);
	void setLOSColor(glm::vec4 color);

	void setCloseCombatDistance(float distance);
	void setIsInCloseCombatDistance(bool state);
	void setCloseCombatColour(glm::vec4 color);

	glm::vec4 m_LOSColor;
	glm::vec4 m_CloseCombatColour;
private:
	glm::vec2 m_gridPosition;
	glm::vec2 m_orientation;
	
	float m_LOSDistance;
	bool m_hasLOS;

	float m_closeCombatDistance;
	bool m_isInCloseCombatDistance;
	//glm::vec4 m_LOSColor;
};

#endif
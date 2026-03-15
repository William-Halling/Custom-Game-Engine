#pragma once

#include "TerrainNode.h"

class NPC_AI
{
	public:
		std::vector<TerrainNode> path;
		Terrain terrain;

		NPC_AI() {}
		NPC_AI(Terrain* terrain);


		void wander();
		void setStartNode(int x, int y);
		void setEndNode(int x, int y);
		std::vector<TerrainNode> calculatePath();
		float calculateH(TerrainNode& a, TerrainNode& b);
		std::vector<Node> getNeighbours(TerrainNode& node);
		bool checkCollision(TerrainNode& a, TerrainNode& b);


	private:

		Terrain* m_WorldEnvironment;
		std::vector<TerrainNode> m_TerrainNodes;
};

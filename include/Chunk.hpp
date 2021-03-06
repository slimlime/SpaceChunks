#ifndef CHUNK_HPP
#define CHUNK_HPP

#include "Engine.hpp"
#include "World.hpp"
#include "Block.hpp"

// Set the World Manager class here to prevent compile issues
class World;

class Chunk
{
public:
	Chunk(glm::vec3 pos, Engine *engine, World *world, int id);

	void CreateChunk();

	~Chunk();

	void Render();
	void Rebuild();

	glm::vec3 GetCenter();
	glm::vec3 GetPosition();
	Chunk* FindChunk(glm::vec3 pos);

	BlockType GetTheoreticalBlock(glm::vec3 pos, glm::vec3 offset0, glm::vec3 offset1, glm::vec3 offset2);
	BlockType GetTheoreticalBlock(glm::vec3 pos);

	BlockType GetBlock(int x, int y, int z);
	BlockType GetBlock(glm::vec3 pos);

	void SetBlock(int x, int y, int z, BlockType type);
	
	float CalculateNoiseValue(glm::vec3 pos, glm::vec3 offset, float scale);
	bool IsTransparent(int x, int y, int z);

	bool ShouldRebuildChunk();
	bool IsChunkLoaded();

	Chunk* GetChunk(int x, int y, int z);

	Block*** GetBlockArray()
	{
		return m_pBlocks;
	}

	int GetChunkId() {
		return m_pChunkGlobalID;
	}

private:	
	// The chunk Position
	glm::vec3 m_position;
	// 3D array of blocks
	Block*** m_pBlocks;
	// Boolean for when vhunk is modified
	bool m_pChanged;
	// Is the chunk actaully loaded
	bool m_pLoaded = false;

	// The chunk ID
	int m_pChunkGlobalID;

	// 
	Engine *m_pRenderer;
	World* m_pWorld;

	GLuint m_pChunkID;
};

#endif // CHUNK_HPP
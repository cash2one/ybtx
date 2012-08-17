#pragma once
#include "../IO/VersionMapChunk.h"

namespace bly
{
class CTerrainMesh;
}

namespace Map
{

/// �߼���.
class RegionLogicalHeight : public IO::DataChunk
{
	DeclareChunk(RegionLogicalHeight);
public:
	RegionLogicalHeight();
	virtual ~RegionLogicalHeight();

	/// д����
	void Write();
	/// �����ж�ȡ
	void Read();

	/// ��������.
	/// @param	CTerrainMesh * terrain
	/// @param	uint index	Region����
	/// @return	void
	void LoadFromTerrain(CTerrainMesh* terrain, uint index);

	enum
	{
		REGION_WIDTH_IN_GRID = 16,
		REGION_WIDTH_IN_VERTEX = REGION_WIDTH_IN_GRID + 1,
		REGION_VERTEX_NUM = REGION_WIDTH_IN_VERTEX*REGION_WIDTH_IN_VERTEX
	};

private:
	short height[REGION_VERTEX_NUM];
};

}// namespace Map
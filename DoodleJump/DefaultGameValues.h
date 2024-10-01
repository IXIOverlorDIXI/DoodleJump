#pragma once

#define DGV DefaultGameValues

class DefaultGameValues {
public:
	class Window {
	public:
		static const int DefaultWidth = 800;
		static const int DefaultHeight = 600;
		static int CurrentWidth;
		static int CurrentHeight;
	};

	class Game
	{
	public:
		static const int DefaultTickAmount = 60;
		static const int BlindModeTimer = 2000;
		static const int ScoreAmountToSpawnEnemy = 500;
		static const int ScoreAmountToSpawnJetpack = 1000;
		static const int ScoreAmountToSpawnRandomAbility = 700;
		static const int IncreaseJumpSpeedModifier = 15;
		static const int DecreaseJumpSpeedModifier = 5;
		static const int MinJumpSpeedModifier = 50;
		static const int MaxJumpSpeedModifier = 300;
		static float ScoreModifier;
	};

	class UI
	{
	public:
		class Score
		{
		public:
			static const int DefaultRowIndent = 2;
			static const int DefaultOverallScoreCaptionWidth = 80;
			static const int DefaultOverallScoreCaptionHeight = 25;
			static const int DefaultJumpedOnCaptionWidth = 40;
			static const int DefaultJumpedOnCaptionHeight = 25;
			static const int DefaultJumpedOverCaptionWidth = 40;
			static const int DefaultJumpedOverCaptionHeight = 25;
			static const int DefaultNumberWidth = 30;
			static const int DefaultNumberHeight = 25;
			static int CurrentRowIndent;
			static int CurrentOverallScoreCaptionWidth;
			static int CurrentOverallScoreCaptionHeight;
			static int CurrentJumpedOnCaptionWidth;
			static int CurrentJumpedOnCaptionHeight;
			static int CurrentJumpedOverCaptionWidth;
			static int CurrentJumpedOverCaptionHeight;
			static int CurrentNumberWidth;
			static int CurrentNumberHeight;
		};
	};

	class Entity
	{
	public:
		class Doodle
		{
		public:
			static const int DefaultWidth = 124;
			static const int DefaultHeight = 120;
			static int CurrentWidth;
			static int CurrentHeight;
			static const int DefaultJumpDistance = 250;
			static const int DefaultHorisontalMoveSpeed = 5;
			static const int DefaultVerticalMoveSpeed = 7;
			static int CurrentJumpDistance;
			static int CurrentHorisontalMoveSpeed;
			static int CurrentVerticalMoveSpeed;
		};

		class Platform
		{
		public:
			static const int DefaultWidth = 114;
			static const int DefaultHeight = 29;
			static const int DefaultCreationEdgeFromTop = 100;
			static const int DefaultDestructionEdgeFromBottom = 10;
			static const int DefaultMinSideIndentFromPrevious = 3;
			static const int DefaultMinTopIndentFromPrevious = 50;
			static const int DefaultMaxSideIndentFromPrevious = 500;
			static const int DefaultMaxTopIndentFromPrevious = 100;
			static const int DefaultBottomCreationEdge = 50;
			static const int DefaultBorderIndent = 5;
			static int CurrentWidth;
			static int CurrentHeight;
			static int CurrentCreationEdgeFromTop;
			static int CurrentDestructionEdgeFromBottom;
			static int CurrentMinSideIndentFromPrevious;
			static int CurrentMinTopIndentFromPrevious;
			static int CurrentMaxSideIndentFromPrevious;
			static int CurrentMaxTopIndentFromPrevious;
			static int CurrentBorderIndent;
			static int CurrentBottomCreationEdge;
		};

		class Bullet
		{
		public:
			static const int DefaultDiameter = 16;
			static const int DefaultDestructionEdgeFromBorder = 20;
			static const int DefaultVelocity = 10;
			static int CurrentDiameter;
			static int CurrentDestructionEdgeFromBorder;
			static int CurrentVelocity;
		};

		class Enemy
		{
		public:
			static const int DefaultWidth = 94;
			static const int DefaultHeight = 72;
			static const int DefaultIndentFromPlatform = 15;
			static const int DefaultDestructionEdgeFromBottom = 10;
			static float SpawnChance;
			static int CurrentWidth;
			static int CurrentHeight;
			static int CurrentIndentFromPlatform;
			static int CurrentDestructionEdgeFromBottom;
		};

		class Spring {
		public:
			static const int DefaultDestructionEdgeFromBottom = 10;
			static int CurrentDestructionEdgeFromBottom;
			static float SpawnChance;

			class DefaultSpring
			{
			public:
				static const int DefaultWidth = 36;
				static const int DefaultHeight = 25;
				static float JumpModifier;
				static int CurrentWidth;
				static int CurrentHeight;
			};

			class Trampoline
			{
			public:
				static const int DefaultWidth = 73;
				static const int DefaultHeight = 29;
				static float JumpModifier;
				static int CurrentWidth;
				static int CurrentHeight;
			};
		};

		class Ability {
		public:
			static const int DefaultDestructionEdgeFromBottom = 10;
			static int CurrentDestructionEdgeFromBottom;
			static float FlyVelocityModifier;

			class Jetpack {
			public:
				static const int FlyTime = 10000;
				static const int DefaultWidth = 50;
				static const int DefaultHeight = 74;
				static float SpawnChance;
				static int CurrentWidth;
				static int CurrentHeight;
			};
			class Hat {
			public:
				static const int FlyTime = 3000;
				static const int DefaultWidth = 63;
				static const int DefaultHeight = 40;
				static float SpawnChance;
				static int CurrentWidth;
				static int CurrentHeight;
			};
		};
	};

	class Collider
	{
	public:
		class Priority
		{
		public:
			static const int DoodleBody = 5;
			static const int DoodleFeet = 1;
			static const int DoodleBullet = 2;
			static const int EnemyBody = 3;
			static const int EnemyHead = 4;
			static const int Spring = 6;
			static const int Platform = 7;
			static const int Ability = 4;
			static const int Unknown = 10;
		};

		class DoodleBullet
		{
		public:
			static const int DefaultXIndent = 0;
			static const int DefaultYIndent = 0;
			static const int DefaultRadius = 6;
			static int CurrentXIndent;
			static int CurrentYIndent;
			static int CurrentRadius;
		};
		class DoodleFeet {
		public:
			static const int DefaultXIndent = 30;
			static const int DefaultYIndent = 102;
			static const int DefaultWidth = 60;
			static const int DefaultHeight = 22;
			static int CurrentXIndent;
			static int CurrentYIndent;
			static int CurrentWidth;
			static int CurrentHeight;
		};
		class DoodleBody {
		public:
			static const int DefaultXIndent = 30;
			static const int DefaultYIndent = 30;
			static const int DefaultWidth = 60;
			static const int DefaultHeight = 84;
			static int CurrentXIndent;
			static int CurrentYIndent;
			static int CurrentWidth;
			static int CurrentHeight;
		};

		class Platform {
		public:
			static const int DefaultXIndent = 0;
			static const int DefaultYIndent = 0;
			static const int DefaultWidth = 114;
			static const int DefaultHeight = 15;
			static int CurrentXIndent;
			static int CurrentYIndent;
			static int CurrentWidth;
			static int CurrentHeight;
		};

		class EnemyHead {
		public:
			static const int DefaultXIndent = 0;
			static const int DefaultYIndent = 0;
			static const int DefaultWidth = 72;
			static const int DefaultHeight = 22;
			static int CurrentXIndent;
			static int CurrentYIndent;
			static int CurrentWidth;
			static int CurrentHeight;
		};
		class EnemyBody {
		public:
			static const int DefaultXIndent = 0;
			static const int DefaultYIndent = 0;
			static const int DefaultWidth = 94;
			static const int DefaultHeight = 72;
			static int CurrentXIndent;
			static int CurrentYIndent;
			static int CurrentWidth;
			static int CurrentHeight;
		};

		class Spring {
		public:
			class DefaultSpring
			{
			public:
				static const int DefaultXIndent = 0;
				static const int DefaultYIndent = 0;
				static const int DefaultWidth = 36;
				static const int DefaultHeight = 25;
				static int CurrentXIndent;
				static int CurrentYIndent;
				static int CurrentWidth;
				static int CurrentHeight;
			};

			class Trampoline
			{
			public:
				static const int DefaultXIndent = 0;
				static const int DefaultYIndent = 0;
				static const int DefaultWidth = 73;
				static const int DefaultHeight = 29;
				static int CurrentXIndent;
				static int CurrentYIndent;
				static int CurrentWidth;
				static int CurrentHeight;
			};
		};

		class Ability {
		public:
			class Jetpack {
			public:
				static const int DefaultXIndent = 0;
				static const int DefaultYIndent = 0;
				static const int DefaultWidth = 50;
				static const int DefaultHeight = 74;
				static int CurrentXIndent;
				static int CurrentYIndent;
				static int CurrentWidth;
				static int CurrentHeight;
			};
			class Hat {
			public:
				static const int DefaultXIndent = 0;
				static const int DefaultYIndent = 0;
				static const int DefaultWidth = 63;
				static const int DefaultHeight = 40;
				static int CurrentXIndent;
				static int CurrentYIndent;
				static int CurrentWidth;
				static int CurrentHeight;
			};
		};
	};
};
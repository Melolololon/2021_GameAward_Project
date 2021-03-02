#include "Game.h"
#include<Library.h>
#include"SceneManager.h"
#include"ObjectManager.h"

#include"Play.h"


Game::Game() {}

Game::~Game() {}

Game* Game::getInstance()
{
	static Game game;
	return &game;
}

void Game::run()
{
	initialize();
	while (1)
	{
		Library::roopStartProcess();
		update();
		draw();
		Library::roopEndProcess();
		if (Library::getIsEnd())break;
	}

	end();
}

void Game::initialize()
{
#pragma region ���C�u����������_�ݒ�
	Library::initialize(1280, 720, { 0,0,0,255 }, L"Game");
	Library::setCameraNearAndFar(0.1, 100);
	Library::setFramesPerSecond60(true);
#pragma endregion

#pragma region �}�l�[�W���[������_�ݒ�
	ObjectManager::getInstance()->initialize();
	ObjectManager::getInstance()->reserveObjectArray(100);
	CollisionFlag f;
	f.board = false;
	f.lineSegment = false;
	f.plane = false;
	f.ray = false;
	f.sphere = true;
	ObjectManager::getInstance()->setCollisionFlag3D(f);

	SceneManager::getInstace()->initialize();
	SceneManager::getInstace()->addScene("Play", new Play());
#pragma endregion

#pragma region �o�b�t�@�֌W

	
#pragma endregion

}


void Game::end()
{
#pragma region �}�l�[�W���[�I��
	ObjectManager::getInstance()->end();
	SceneManager::getInstace()->end();
#pragma endregion


	Library::end();//��΂ɍŌ�ɏ���
}

void Game::update()
{
	SceneManager::getInstace()->update();

}

void Game::draw()
{
	SceneManager::getInstace()->draw();
}
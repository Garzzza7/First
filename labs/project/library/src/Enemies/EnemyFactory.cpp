#include "Enemies/EnemyFactory.h"

EnemyFactory::EnemyFactory(){
this->resourceRegistry = ResourceRegistry::GetInstance();
}

Enemy *EnemyFactory::CreateEnemy(unsigned int id) {

    switch (id) {
        case GOOMBA_ENTITY_ID:
            return new Goomba(resourceRegistry->getPresetById(GOOMBA_ENTITY_ID));
        case PPLANT_ENTITY_ID:
            return new PPlant(resourceRegistry->getPresetById(PPLANT_ENTITY_ID));
        default:
            throw std::runtime_error(
                    "Enemy factory could not find the enemy assigned with this enemy id: " + std::to_string(id));
    }

}
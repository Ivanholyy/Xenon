#ifndef CAMERA_H
#define CAMERA_H 1

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum movement_t {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;

class CCamera {

public:
    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldup;

    float yaw;
    float pitch;

    float movementspeed;
    float mousesensitivity;
    float zoom;

    CCamera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : front(glm::vec3(0.0f, 0.0f, -1.0f)), movementspeed(SPEED), mousesensitivity(SENSITIVITY), zoom(ZOOM)
    {
        this->position = position;
        this->worldup = up;
        this->yaw = yaw;
        this->pitch = pitch;
        updatecameravectors();
    }

    CCamera(float posx, float posy, float posz, float upx, float upy, float upz, float yaw, float pitch) : front(glm::vec3(0.0f, 0.0f, -1.0f)), movementspeed(SPEED), mousesensitivity(SENSITIVITY), zoom(ZOOM)
    {
        this->position = glm::vec3(posx, posy, posz);
        this->worldup = glm::vec3(upx, upy, upz);
        this->yaw = yaw;
        this->pitch = pitch;
        updatecameravectors();
    }

    glm::mat4 getviewmatrix();
    void processkeyboard(movement_t direction, float deltatime);
    void processmousemovement(float xoffset, float yoffset, bool constrainpitch = true);
    void processmousescroll(float yoffset);

private:
    void updatecameravectors();
};

#endif

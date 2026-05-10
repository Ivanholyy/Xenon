#include "camera.h"

glm::mat4 CCamera::getviewmatrix() {
    return glm::lookAt(position, position + front, up);
}

void CCamera::processkeyboard(movement_t direction, float deltatime) {

    float velocity = movementspeed * deltatime;
    if (direction == FORWARD)
        position += front * velocity;
    if (direction == BACKWARD)
        position -= front * velocity;
    if (direction == LEFT)
        position -= right * velocity;
    if (direction == RIGHT)
        position += right * velocity;
}

void CCamera::processmousemovement(float xoffset, float yoffset, bool constrainpitch) {

    xoffset *= mousesensitivity;
    yoffset *= mousesensitivity;

    yaw   += xoffset;
    pitch += yoffset;

    if (constrainpitch) {
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
    }

    updatecameravectors();
}

void CCamera::processmousescroll(float yoffset) {

    zoom -= (float)yoffset;
    if (zoom < 1.0f)
        zoom = 1.0f;
    if (zoom > 45.0f)
        zoom = 45.0f;
}

void CCamera::updatecameravectors() {

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    this->front = glm::normalize(front);
    right = glm::normalize(glm::cross(front, worldup));
    up    = glm::normalize(glm::cross(right, front));
}

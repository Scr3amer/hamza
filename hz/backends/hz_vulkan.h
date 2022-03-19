#ifndef HZ_VULKAN_H
#define HZ_VULKAN_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <hz/hz.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct hz_vulkan_renderer_t {
    GLFWwindow *window;
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkPhysicalDevice physicalDevice;
    VkDevice device;
    VkSurfaceKHR surface;
    VkSwapchainKHR swapchain;
    VkQueue graphicsQueue, presentQueue;
    uint32_t swapchainImageCount;
    VkImage *swapchainImages;
    VkFormat swapchainImageFormat;
    VkExtent2D swapchainExtent;
    VkImageView *swapchainImageViews;

    VkRenderPass renderPass;
    VkPipelineLayout pipelineLayout;

    int enableDebug;
    int enableVSync;
} hz_vulkan_renderer_t;

hz_vulkan_renderer_t *
hz_vulkan_renderer_create(GLFWwindow *window, int enableDebug);

void
hz_vulkan_renderer_release(hz_vulkan_renderer_t *renderer);

#ifdef __cplusplus
};
#endif

#endif // HZ_VULKAN_H
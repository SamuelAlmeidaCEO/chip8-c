#include "chip8/chip8.h"

#include <stdio.h>
#include <SDL2/SDL.h>

int chip8_init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}

chip8 *chip8_create()
{
    chip8 *chip8 = malloc(sizeof(chip8));
    chip8->window = chip8_create_window();
    chip8->ram = chip8_create_ram();
    return chip8;
}

void chip8_destroy(chip8 *chip8)
{
    chip8_destroy_window(chip8->window);
    chip8_destroy_ram(chip8->ram);
    chip8_destroy_rom(chip8->rom);
    free(chip8);
}

static void chip8_loop(chip8_window *window)
{
    if (!window->running)
    {
        printf("Quitting...\n");
    }
}

void chip8_run(chip8 *chip8, const char *rom_path)
{
    chip8->rom = chip8_create_rom(rom_path);
    chip8_load_rom(chip8->rom, chip8->ram);
    chip8_loop_window(chip8->window, chip8_loop);
}
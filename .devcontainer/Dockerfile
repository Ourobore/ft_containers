FROM debian:bullseye

# Setting up working environment
RUN apt-get update && apt-get -y install \
    # C++ dependencies
    clang \
    clangd \
    clang-format \
    make \
    valgrind \
    # Utilities
    git \
    curl \
    htop \
    # Install zsh and oh-my-zsh and make zsh the default shell
    zsh ;\
    cd / && sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)" \
    && chsh -s $(command -v zsh)



# C++ dependencies:
#   clang
#   clang-format
#   make
#   valgrind

# Utilities:
#   git
#   curl
#   htop
#   zsh
#   oh-my-zsh

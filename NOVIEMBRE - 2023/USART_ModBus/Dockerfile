# Usa una imagen base de Ubuntu
FROM ubuntu:latest

# Actualiza los repositorios e instala herramientas necesarias
# Download Linux support tools
RUN apt-get update && \
         apt-get clean && \ 
         apt-get install -y \
             build-essential \
             wget \
             curl

# Crea y establece el directorio de trabajo
WORKDIR /home/dev
ADD . /home/dev

# RUN wget -qO- https://developer.arm.com/-/media/Files/downloads/gnu-rm/10.3-2021.10/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux.tar.bz2 | tar -xj
# RUN Wget 
# ENV PATH $PATH:/home/dev/gcc-arm-none-eabi-10.3-2021.10/bin

RUN wget https://github.com/Kitware/CMake/releases/download/v3.22.0/cmake-3.22.0.tar.gz && \
    tar -xzvf cmake-3.22.0.tar.gz && \
    cd cmake-3.22.0 && \
    ./bootstrap && \
    make && \
    make install && \
    cd .. && \
    rm -rf cmake-3.22.0*

RUN wget https://github.com/ninja-build/ninja/releases/download/v1.10.2/ninja-linux.zip && \
    unzip ninja-linux.zip -d /home/dev && \
    rm ninja-linux.zip
WORKDIR /home/app

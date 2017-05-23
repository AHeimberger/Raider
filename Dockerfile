FROM ubuntu:16.04
MAINTAINER aheimberger


# setup default build arguments
ARG USER_ID=no-id
ARG USER_NAME=raider
ARG GIT_BRANCH=develop
ARG GIT_URL=https://github.com/AHeimberger/Raider.git
ARG GIT_HASH=no-hash


# general requirements
RUN apt-get -qq update && \
    apt-get -qq dist-upgrade && \
    apt-get install -qq -y --no-install-recommends \
    \
    software-properties-common python-software-properties \
    build-essential \
    git \
    openssl \
    ca-certificates


# install Qt 5.6
# all packages: https://launchpad.net/~beineri
# found here: https://launchpad.net/~beineri/+archive/ubuntu/opt-qt562-xenial
RUN add-apt-repository -y ppa:beineri/opt-qt562-xenial && \
    apt-get -qq update
RUN apt-get -qq install \
    qt56base \
    qt56declarative \
    qt56imageformats \
    qt56quickcontrols \
    qt56quickcontrols2 \
    qt56svg \
    qt56serialport \
    qt56tools \
    qt56translations \
    qt56x11extras
ENV PATH=${PATH}:/opt/qt56/bin/


# setup environment directories
ENV DIR_HOME        /home/${USER_NAME}
ENV DIR_DEPLOY      ${DIR_HOME}/deploy
ENV DIR_PROJECT     ${DIR_HOME}/project



# lets create the user
RUN useradd -ms /bin/bash ${USER_NAME}
USER ${USER_NAME}


# setup directories
RUN mkdir -p ${DIR_DEPLOY} && \
    mkdir -p ${DIR_PROJECT}


# test it from remote
RUN git clone -b ${GIT_BRANCH} ${GIT_URL} ${DIR_PROJECT} && \
    if [ ${GIT_HASH} != "no-hash" ]; then cd ${DIR_PROJECT} && git reset --hard ${GIT_HASH}; fi


# test it locally
# COPY . ${DIR_PROJECT}


# setup the working directory
WORKDIR ${DIR_PROJECT}


# setup entrypoint function
ENTRYPOINT ["./scripts/entrypoint.sh"]
CMD ["help"]

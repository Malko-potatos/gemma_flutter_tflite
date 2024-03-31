cmake_minimum_required(VERSION 3.10)

project(ffigen_app_library VERSION 0.0.1 LANGUAGES C CXX) # C++도 사용하므로 CXX 추가

# FetchContent 모듈 추가
include(FetchContent)

# Highway 라이브러리
FetchContent_Declare(highway
  GIT_REPOSITORY https://github.com/google/highway.git
  GIT_TAG da250571a45826b21eebbddc1e50d0c1137dee5f
)
FetchContent_MakeAvailable(highway)

# SentencePiece 라이브러리
FetchContent_Declare(sentencepiece
  GIT_REPOSITORY https://github.com/google/sentencepiece
  GIT_TAG 53de76561cfc149d3c01037f0595669ad32a5e7c
)
FetchContent_MakeAvailable(sentencepiece)

# Gemma 라이브러리
# 주의: Gemma의 실제 저장소 URL과 태그를 확인해야 함
FetchContent_Declare(gemma
  GIT_REPOSITORY <Gemma의 실제 저장소 URL>
  GIT_TAG origin/main
)
FetchContent_MakeAvailable(gemma)

# ffigen_app 라이브러리 생성
add_library(ffigen_app SHARED
  "ffigen_app.c"
)

set_target_properties(ffigen_app PROPERTIES
  PUBLIC_HEADER ffigen_app.h
  OUTPUT_NAME "ffigen_app"
)

target_compile_definitions(ffigen_app PUBLIC DART_SHARED_LIB)

# 라이브러리와 헤더 파일 위치 연결
target_link_libraries(ffigen_app PRIVATE
  libgemma # gemma 라이브러리 타겟 이름 확인 필요
  hwy
  sentencepiece
)

FetchContent_GetProperties(gemma)
FetchContent_GetProperties(sentencepiece)
target_include_directories(ffigen_app PRIVATE
  ${gemma_SOURCE_DIR}
  ${sentencepiece_SOURCE_DIR}
)


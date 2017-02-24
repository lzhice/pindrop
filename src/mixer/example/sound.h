// Copyright 2015 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PINDROP_MIXER_EXAMPLE_SOUND_H_
#define PINDROP_MIXER_EXAMPLE_SOUND_H_

#include "file_loader.h"

namespace pindrop {

class SoundCollection;

// A sound represents either buffered or streaming audio file.
//
// This class represents the sound interface to the underlying audio mixer
// backend being used.
class Sound : public Resource {
 public:
  // Initialize this Sound given the SoundCollection that it is a part of. The
  // sound collection may contain useful metadat about the sound, like whether
  // or not the sound should be streaming, which may impact how you load it.
  void Initialize(const SoundCollection* sound_collection);

  // Load the audio file.
  virtual void Load();
};

}  // namespace pindrop

#endif  // PINDROP_MIXER_EXAMPLE_SOUND_H_

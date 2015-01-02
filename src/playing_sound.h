// Copyright 2014 Google Inc. All rights reserved.
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

#ifndef PINDROP_PLAYING_SOUND_H_
#define PINDROP_PLAYING_SOUND_H_

#include "pindrop/audio_engine.h"

namespace pindrop {

// Represents a sample that is playing on a channel.
struct PlayingSound {
  PlayingSound(AudioEngine::SoundHandle handle,
               AudioEngine::ChannelId cid,
               unsigned int frame);
  PlayingSound(const PlayingSound& other);
  PlayingSound& operator=(const PlayingSound& other);
  ~PlayingSound();

  AudioEngine::SoundHandle handle;
  AudioEngine::ChannelId channel_id;
  unsigned int frame_created;
};

// Sort by priority. In the case of two sounds with the same priority, sort
// the newer one as being higher priority. Higher priority elements have lower
// indicies.
//
// TODO(amablue): This should actually have a boolean return value so that it
// works with std::sort correctly.
int PlayingSoundComparitor(const PlayingSound& a, const PlayingSound& b);

}  // namespace pindrop

#endif  // PINDROP_PLAYING_SOUND_H_


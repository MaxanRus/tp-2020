#pragma once

#include <gtest/gtest.h>
#include <Weather.h>
#include <random>

class FakeWeather : public Weather {
 public:
  float GetRand();
  cpr::Response Get(const std::string& city, const cpr::Url& url) override;
 private:
  std::mt19937 rnd;
};

class FakeWeatherFailLoadResponse : public Weather {
 public:
  cpr::Response Get(const std::string& city, const cpr::Url& url) override;
};

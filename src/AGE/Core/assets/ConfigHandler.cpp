/**
 * Provides the ConfigHandler class used by the AssetManager to manage all
 * ConfigReader assets for the application.
 *
 * @file src/AGE/Core/assets/ConfigHandler.cpp
 * @author Ryan Lindeman
 * @date 20120428 - Initial Release
 * @date 20120514 - Don't throw exception on new
 */
 
#include <AGE/Core/assets/ConfigHandler.hpp>
#include <AGE/Core/loggers/Log_macros.hpp>
 
namespace AGE
{
  ConfigHandler::ConfigHandler() :
    TAssetHandler<ConfigReader>()
  {
    ILOG() << "ConfigHandler::ctor()" << std::endl;
  }
 
  ConfigHandler::~ConfigHandler()
  {
    ILOG() << "ConfigHandler::dtor()" << std::endl;
  }

  bool ConfigHandler::loadFromFile(const assetID theAssetID, ConfigReader& theAsset)
  {
    // Start with a return result of false
    bool anResult = false;

    // Retrieve the filename for this asset
    std::string anFilename = getFilename(theAssetID);

    // Was a valid filename found? then attempt to load the asset from anFilename
    if(anFilename.length() > 0)
    {
      // Load the asset from a file
      anResult = theAsset.loadFromFile(anFilename);
    }
    else
    {
      ELOG() << "ConfigHandler::loadFromFile(" << theAssetID
        << ") No filename provided!" << std::endl;
    }

    // Return anResult of true if successful, false otherwise
    return anResult;
  }

  bool ConfigHandler::loadFromMemory(const assetID theAssetID, ConfigReader& theAsset)
  {
    // Start with a return result of false
    bool anResult = false;

    // TODO: Add LoadFromMemory support to ConfigReader

    // Return anResult of true if successful, false otherwise
    return anResult;
  }

  bool ConfigHandler::loadFromNetwork(const assetID theAssetID, ConfigReader& theAsset)
  {
    // Start with a return result of false
    bool anResult = false;

    // TODO: Add load from network for this asset

    // Return anResult of true if successful, false otherwise
    return anResult;
  }
} // namespace AGE
 
/**
 * Copyright (c) 2010-2012 Ryan Lindeman
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

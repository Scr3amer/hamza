﻿NDSummary.OnToolTipsLoaded("File:hz.c",{3:"<div class=\"NDToolTip TInformation LC\"><div class=\"TTSummary\">This file is licensed under MIT.</div></div>",8:"<div class=\"NDToolTip TStruct LC\"><div class=\"TTSummary\">A struct to store a buffer.&nbsp; This is also used by &lt;hz_deserializer_t&gt; to read off bytes.</div></div>",9:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype9\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">HZ_STATIC hz_stream_t hz_stream_create(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span>&nbsp;</td><td class=\"PType\">uint8_t&nbsp;</td><td class=\"PSymbols\">*</td><td class=\"PName last\">data,</td></tr><tr><td class=\"first\"></td><td class=\"PType\">size_t&nbsp;</td><td></td><td class=\"PName last\">size</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Creates a byte stream, holds data and a bump pointer allowing seeking, unpacking various primitives from memory.</div></div>",11:"<div class=\"NDToolTip TStruct LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype11\"><div class=\"CPEntry TStruct Current\"><div class=\"CPModifiers\"><span class=\"SHKeyword\">struct</span></div><div class=\"CPName\">hz_segment_t</div></div></div><div class=\"TTSummary\">A struct used to store a segment of text and the information required to shape it.</div></div>",13:"<div class=\"NDToolTip TEnumeration LC\"><div class=\"TTSummary\">https://&#8203;docs&#8203;.microsoft&#8203;.com&#8203;/en-us&#8203;/typography&#8203;/opentype&#8203;/spec&#8203;/cmap&#8203;#platform-ids</div></div>",14:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype14\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\">HZ_STATIC <span class=\"SHKeyword\">int</span> hz_search_prev_glyph(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">hz_buffer_t&nbsp;</td><td class=\"PSymbols\">*</td><td class=\"PName last\">buffer,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">index,</td></tr><tr><td class=\"PType first\">uint16_t&nbsp;</td><td></td><td class=\"PName last\">m1,</td></tr><tr><td class=\"PType first\">uint16_t&nbsp;</td><td></td><td class=\"PName last\">m2</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">Find previous glyph while making use of m1 and m2 glyph class masks.&nbsp; It searches for a glyph with m2 classes and ensures the glyphs until then match with m1.&nbsp; NOTE: this is useful to implement MARK_TO_BASE or MARK_TO_LIGATURE positioning.</div></div>",15:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype15\" class=\"NDPrototype WideForm\"><div class=\"PSection PParameterSection CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> hz_shape_plan_apply_gsub_lookup(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">hz_shape_plan_t&nbsp;</td><td class=\"PSymbols\">*</td><td class=\"PName last\">plan,</td></tr><tr><td class=\"PType first\">hz_feature_t&nbsp;</td><td></td><td class=\"PName last\">feature,</td></tr><tr><td class=\"PType first\">uint16_t&nbsp;</td><td></td><td class=\"PName last\">lookupIndex,</td></tr><tr><td class=\"PType first\">hz_buffer_t&nbsp;</td><td class=\"PSymbols\">*</td><td class=\"PName last\">in,</td></tr><tr><td class=\"PType first\">hz_buffer_t&nbsp;</td><td class=\"PSymbols\">*</td><td class=\"PName last\">out,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">v1,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">v2,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">depth</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div><div class=\"TTSummary\">apply GSUB lookup table to glyph range [v1,v2] within the segment buffer.&nbsp; depth is the current nested lookup depth index, as this can be recursive.</div></div>"});